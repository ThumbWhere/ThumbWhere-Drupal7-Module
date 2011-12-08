namespace DrupalUtil
{
    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Text;
    using System.Xml;
    using System.Xml.Xsl;
    using System.Xml.XPath;
    using System.IO;
    using System.Security.Cryptography;
    using System.Threading;
    using ICSharpCode.SharpZipLib;
    using ICSharpCode.SharpZipLib.Tar;
    using ICSharpCode.SharpZipLib.Zip;
    using ICSharpCode.SharpZipLib.GZip;
    using Tamir.SharpSsh;


    /// <summary>
    /// Small Utility that can create and maintain a Drupal Module Status Update Feed
    /// </summary>
    class Program
    {

        /// <summary>
        /// Return a list of know commands.
        /// </summary>
        static void KnownCommands()
        {
            Console.WriteLine("");
            Console.WriteLine("Known commands: add.help,new,ssh");
            Console.WriteLine("");

            Usage("add");
            Usage("help");
            Usage("new");
            Usage("ssh");

        }

        /// <summary>
        /// Return a list of know commands.
        /// </summary>
        static void KnownOptions()
        {
            Console.WriteLine("");
            Console.WriteLine("Known options: --recommended --supported --default --exitcleanonerror");
            Console.WriteLine("");

        }


        /// <summary>
        /// Explain the usage of a specifig command.
        /// </summary>
        /// <param name="command">The command we want to explain.</param>
        static void Usage(string command)
        {
            Console.WriteLine("");
            switch (command.ToLower())
            {
                case "new":
                    {
                        Console.WriteLine("new - Creates a new module");
                        Console.WriteLine("");
                        Console.WriteLine("new name maintainer api description");
                        Console.WriteLine("");
                        Console.WriteLine("eg: new guitar memyselfandi 7.x http://example.com/release-history/");
                    }
                break;

                case "ssh":
                    {
                        Console.WriteLine("ssh - Starts a remote ssh session and runs the supplied commands");
                        Console.WriteLine("");
                        Console.WriteLine("ssh user commands");
                        Console.WriteLine("");
                        Console.WriteLine("ssh user:password@example.com \"cd src\" \"git pull\" \"tar cvPpzf release56.tar.gz build\"");                        
                    }
                break;

                case "add":
                    {
                        Console.WriteLine("add - Adds a release to the manifest.");
                        Console.WriteLine("");
                        Console.WriteLine("add folder name api increment [type] [stream] [build]");
                        Console.WriteLine("");
                        Console.WriteLine("increment must be 'major' or 'patch'");
                        Console.WriteLine("  'major' will increment the major version. eg. 2.3 -> 3.0");
                        Console.WriteLine("  'patch' will increment the major version. eg  2.3 -> 3.4");
                        Console.WriteLine("");
                        Console.WriteLine(@"eg: add C:\work\hard\ guitar 7.x major");
                        Console.WriteLine(@"eg: add C:\work\easy\ guitar 7.x patch \'Bug fixes\' dev 456");
                    }
                    break;

                case "help":
                    {
                        Console.WriteLine("help - Provides help");
                        Console.WriteLine("");
                        Console.WriteLine("help [command]");
                        Console.WriteLine("");
                        Console.WriteLine("eg: help");
                        Console.WriteLine("    help new");
                    }
                    break;

                default:
                    {
                        Console.WriteLine("Unknown command '{0}'", command);
                        KnownCommands();
                    }
                    break;
            }

            Console.WriteLine("");
        }

        /// <summary>
        /// Called when the command is called with the wrong number of arguments
        /// </summary>
        /// <param name="command"></param>
        static void NotEnoughArguments(string command)
        {
            Console.WriteLine("");
            Console.WriteLine("Not enough arguments.");
            Console.WriteLine("");
            Console.WriteLine("Here is the correct usage of '{0}'", command);
            Console.WriteLine("");
            Console.WriteLine("-----------------------------------------");
            Console.WriteLine("");

            Usage(command);
        }

        /// <summary>
        /// Returns the MD5 File Hash from a passed full file path
        /// </summary>
        /// <param name="p_file_path">The full path of the file</param>
        /// <returns>a MD5 Hash as a string</returns>
        static public string MD5FileHash(string p_file_path)
        {
            MD5CryptoServiceProvider l_csp = new MD5CryptoServiceProvider();

            // compute hash
            using (FileStream l_stream = File.Open(p_file_path, FileMode.Open, FileAccess.Read, FileShare.Read))
            {
                byte[] l_hash = l_csp.ComputeHash(l_stream);
                l_stream.Close();

                return Bytes2Hex(l_hash);
            }
        }


        /// <summary>
        /// Creates a GZipped Tar file from a source directory
        /// </summary>
        /// <param name="outputTarFilename">Output .tar.gz file</param>
        /// <param name="sourceDirectory">Input directory containing files to be added to GZipped tar archive</param>
        private static void CreateTar(string outputTarFilename, string sourceDirectory)
        {
            using (FileStream fs = new FileStream(outputTarFilename, FileMode.Create, FileAccess.Write, FileShare.None))
            using (Stream gzipStream = new GZipOutputStream(fs))
            using (TarArchive tarArchive = TarArchive.CreateOutputTarArchive(gzipStream))
            {
                AddDirectoryFilesToTar(tarArchive, sourceDirectory, true);
            }
        }

        /// <summary>
        /// Creates a Zip file from a source directory
        /// </summary>
        /// <param name="outputZipFilename">Output .zip file</param>
        /// <param name="sourceDirectory">Input directory containing files to be added to zip/</param>
        private static void CreateZip(string outputZipFilename, string sourceDirectory)
        {

            using (ZipFile zipArchive = ZipFile.Create(outputZipFilename))
            {
                zipArchive.BeginUpdate();
                AddDirectoryFilesToZip(zipArchive, sourceDirectory, true);
                zipArchive.CommitUpdate();
            }
        }


        /// <summary>
        /// Recursively adds folders and files to archive
        /// </summary>
        /// <param name="tarArchive"></param>
        /// <param name="sourceDirectory"></param>
        /// <param name="recurse"></param>
        private static void AddDirectoryFilesToTar(TarArchive tarArchive, string sourceDirectory, bool recurse)
        {
            // Recursively add sub-folders
            if (recurse)
            {
                string[] directories = Directory.GetDirectories(sourceDirectory);
                foreach (string directory in directories)
                    AddDirectoryFilesToTar(tarArchive, directory, recurse);
            }

            // Add files
            string[] filenames = Directory.GetFiles(sourceDirectory);
            foreach (string filename in filenames)
            {
                TarEntry tarEntry = TarEntry.CreateEntryFromFile(filename);
                tarArchive.WriteEntry(tarEntry, true);
            }
        }


        /// <summary>
        /// Recursively adds folders and files to archive
        /// </summary>
        /// <param name="zipArchive"></param>
        /// <param name="sourceDirectory"></param>
        /// <param name="recurse"></param>
        private static void AddDirectoryFilesToZip(ZipFile zipArchive, string sourceDirectory, bool recurse)
        {
            // Add this directory
            zipArchive.AddDirectory(sourceDirectory);

            // Recursively add sub-folders
            if (recurse)
            {
                string[] directories = Directory.GetDirectories(sourceDirectory);
                foreach (string directory in directories)
                {
                    AddDirectoryFilesToZip(zipArchive, directory, recurse);
                }
            }

            // Add files
            string[] filenames = Directory.GetFiles(sourceDirectory);
            foreach (string filename in filenames)
            {
                zipArchive.Add(filename);
            }
        }



        /// <summary>
        /// Converts a Byte array to a hexidecimal string
        /// </summary>
        /// <param name="l_bytes">The byte array</param>
        /// <returns>The hexidecimal string</returns>
        static public string Bytes2Hex(byte[] l_bytes)
        {
            string l_result = "";

            for (int i = 0; i < l_bytes.Length; i++)
            {
                l_result += String.Format("{0:X2}", l_bytes[i]);
            }

            return l_result;
        }


        /// <summary>
        /// Load  text file
        /// </summary>
        /// <param name="p_file_path"></param>
        /// <returns></returns>
        static public string LoadFile(string p_file_path)
        { 
            // Load the file
 
            string l_file_contents;
            StreamReader l_file = File.OpenText(p_file_path);
            l_file_contents = l_file.ReadToEnd();
            l_file.Close();

            return l_file_contents;
        }


        /// <summary>
        /// Writes the passed string to the passed file.
        /// SaveFile writes a log entry if it fails
        /// </summary>
        /// <param name="p_file_path">The full path of the file</param>
        /// <param name="p_string">The string to pass in the file</param>
        static public void SaveFile(string p_file_path, string p_string)
        {
            StreamWriter l_filestream = null;

            try
            {
                // make the master file
                using (l_filestream = File.CreateText(p_file_path))
                {

                    // write the file
                    l_filestream.Write(p_string);

                    // close the file
                    l_filestream.Close();
                }

                // Set the attributes so that we can delete it in the future
                File.SetAttributes(p_file_path, FileAttributes.Normal);
            }

            catch (Exception)
            {

                if (l_filestream != null)
                {
                    l_filestream.Close();
                }

                throw;
            }
        }




        /// <summary>
        /// Our arguments
        /// </summary>
        static string[] Args;

        /// <summary>
        /// The Options
        /// </summary>
        static string[] Options;


        /// <summary>
        /// Used by 'add' - if true then we are recommending this
        /// </summary>
        static bool Recommended = false;

        /// <summary>
        /// Used by 'add' - if true then we are supporting this
        /// </summary>
        static bool Supported = false;

        /// <summary>
        /// Used by 'add' - if true then this is the default
        /// </summary>
        static bool Default = false;

        /// <summary>
        /// User does not care if we nuke something.
        /// </summary>
        static bool Force = false;

        /// <summary>
        /// Pretend that all is good, even if we get an error.
        /// </summary>
        static bool ExitCleanOnError = false;

        /// <summary>
        /// Log the entire conversation between all systems to the console.
        /// </summary>
        static bool LogConversation = false;

        /// <summary>
        /// Filter the input
        /// </summary>
        /// <param name="p_args"></param>
        static void FilterInput(string[] p_args)
        {

            List<string> l_args = new List<string>();
            List<string> l_options = new List<string>();

            foreach (string a in p_args)
            {
                if (a.StartsWith("-"))
                {
                    l_options.Add(a);
                }
                else
                {
                    l_args.Add(a);
                }
            }

            Args = l_args.ToArray();
            Options = l_options.ToArray();

        }


        /// <summary>
        /// Main entry point
        /// </summary>
        /// <param name="args"></param>
        static void Main(string[] args)
        {

            try
            {
                FilterInput(args);

                if (Args.Length == 0)
                {
                    Console.WriteLine("UsageDrupalUtil.exe COMMAND ARGUMENTS");
                    Console.WriteLine("By James Mc Parlane, james@thumbwhere.com");
                    Console.WriteLine("(c) ThumbWhere, 2011");
                    Console.WriteLine("");
                    KnownCommands();
                    KnownOptions();
                    throw new ArgumentException("Called without arguments", "arguments");
                }


                Console.WriteLine("");
                Console.WriteLine("Arguments: ");
                foreach (string a in Args)
                {
                    Console.WriteLine("  {0}", a);
                }

                Console.WriteLine("");
                Console.WriteLine("Options: ");
                foreach (string o in Options)
                {
                    Console.WriteLine("  {0}", o);

                    switch (o)
                    {
                        // Set the recommended version
                        case "--recommended":
                            {
                                Recommended = true;
                            }
                            break;

                        // Set the supported version
                        case "--supported":
                            {
                                Supported = true;
                            }
                            break;

                        // Set the default version
                        case "--default":
                            {
                                Default = true;
                            }
                            break;

                        // Force something through, damn the horses.
                        case "--force":
                            {
                                Force = true;
                            }
                            break;

                        // Force something through, damn the horses.
                        case "--exitcleanonerror":
                            {
                                ExitCleanOnError = true;
                            }
                            break;


                        default:
                            {
                                throw new ArgumentException("Invalid option '" + o + "'", "options");
                            }
                    }
                }
                Console.WriteLine("");


                string command = Args[0];

                switch (command.ToLower())
                {
                    case "help":
                        {

                            if (Args.Length < 1)
                            {
                                NotEnoughArguments(command);
                                Environment.Exit(2);
                                return;
                            }


                            if (Args.Length == 2)
                            {
                                // Help on a specific comand
                                Usage(Args[1]);
                            }
                            else
                            {
                                // General help
                                KnownCommands();
                            }
                        }
                        break;

                    case "new":
                        {

                            if (Args.Length < 5)
                            {
                                NotEnoughArguments(command);
                                Environment.Exit(2);
                                return;
                            }

                            Console.WriteLine("");
                            Console.WriteLine("Creating new Module...");

                            //
                            // Parse the arguments
                            //

                            string name = Args[1].Trim();
                            string maintainer = Args[2].Trim();
                            string api = Args[3].Trim();
                            string url = Args[4].Trim();

                            if (url.EndsWith("/")) url = url.Substring(0, url.Length - 1);


                            Console.WriteLine("");
                            Console.WriteLine("name       = '{0}'", name);
                            Console.WriteLine("maintainer = '{0}'", maintainer);
                            Console.WriteLine("api        = '{0}'", api);
                            Console.WriteLine("url        = '{0}'", url);

                            Console.WriteLine("");

                            //
                            // Populate the XML Tempolate
                            //

                            XmlDocument xmlTemplate = new XmlDocument();
                            xmlTemplate.LoadXml(Resources.manifest_template);

                            XmlNamespaceManager xmlnsManager = new System.Xml.XmlNamespaceManager(xmlTemplate.NameTable);

                            //Add the namespaces used in books.xml to the XmlNamespaceManager.
                            xmlnsManager.AddNamespace("dc", "http://purl.org/dc/elements/1.1/");


                            xmlTemplate.SelectSingleNode("project/title").InnerText = name;
                            xmlTemplate.SelectSingleNode("project/short_name").InnerText = name;
                            xmlTemplate.SelectSingleNode("project/dc:creator", xmlnsManager).InnerText = maintainer;
                            xmlTemplate.SelectSingleNode("project/link").InnerText = url + "/" + name + "/";
                            xmlTemplate.SelectSingleNode("project/api_version").InnerText = api;

                            // Clear our any release information
                            xmlTemplate.SelectSingleNode("project/releases").RemoveAll();

                            //
                            // Create the new module
                            //

                            Directory.CreateDirectory(name);
                            Directory.CreateDirectory(name + "/" + api);

                            string xmlPath = name + "/" + api + "/manifest.xml";

                            if (File.Exists(xmlPath))
                            {
                                Console.WriteLine("There is already a manifest file at '{0}'", xmlPath);
                                if (!Force)
                                {
                                    throw new ArgumentException("Safety feature - we don't let you overwrite if yuu don't specify --force");
                                }
                                else
                                {
                                    Console.WriteLine("... but you specified --force, and we all know what that means.");
                                }
                            }

                            Console.WriteLine("");
                            Console.WriteLine("Saving new XML to '{0}'", xmlPath);

                            // Save the XML
                            xmlTemplate.Save(xmlPath);


                        }
                        break;

                    case "add":
                        {

                            // Our version
                            int majorVersion = 0;
                            int patchVersion = 0;

                            // The base url
                            string url;


                            if (Args.Length < 5)
                            {
                                NotEnoughArguments(command);
                                Environment.Exit(2);
                                return;
                            }

                            Console.WriteLine("");
                            Console.WriteLine("Adding new release...");

                            //
                            // Parse the arguments
                            //

                            string folder = Args[1].Trim();
                            string name = Args[2].Trim();
                            string api = Args[3].Trim();
                            string increment = Args[4].Trim();

                            string type = "Bug fixes";
                            string stream = "release";
                            string build = "";

                            if (Args.Length > 5)
                            {
                                type = Args[5].Trim();
                            }

                            if (Args.Length > 6)
                            {
                                stream = Args[6].Trim();
                            }

                            if (Args.Length > 7)
                            {
                                build = Args[7].Trim();
                            }



                            Console.WriteLine("");
                            Console.WriteLine("folder    = '{0}'", folder);
                            Console.WriteLine("name      = '{0}'", name);
                            Console.WriteLine("api       = '{0}'", api);
                            Console.WriteLine("increment = '{0}'", increment);
                            Console.WriteLine("type      = '{0}'", type);
                            Console.WriteLine("");

                            string xmlPath = name + "/" + api + "/manifest.xml";
                            Console.WriteLine("Loading XML from    {0}", xmlPath);

                            // Get the current manifest
                            XmlDocument xml = new XmlDocument();
                            xml.Load(xmlPath);

                            // Load the current template
                            XmlDocument xmlTemplate = new XmlDocument();
                            xmlTemplate.LoadXml(Resources.manifest_template);
                            XmlNamespaceManager xmlnsManager = new System.Xml.XmlNamespaceManager(xmlTemplate.NameTable);

                            // Find our target releases element
                            XmlElement project = (XmlElement)xml.SelectSingleNode("project");

                            // Find our target releases element
                            XmlElement releases = (XmlElement)project.SelectSingleNode("releases");

                            // Create our new release element
                            XmlElement releaseElement = xml.CreateElement("release");

                            // Populate it
                            releaseElement.InnerXml = xmlTemplate.SelectSingleNode("project/releases/release").InnerXml;

                            // Get the base url
                            url = xml.SelectSingleNode("project/link").InnerText;
                            if (url.EndsWith("/")) url = url.Substring(0, url.Length - 1);


                            // If we have no children, then just add it
                            if (releases.ChildNodes.Count == 0)
                            {
                                // Create the new element
                                releases.AppendChild(releaseElement);
                            }
                            else
                            {
                                Console.WriteLine("There are {0} existing releases.", releases.ChildNodes.Count);

                                // If we have a current release.
                                XmlElement latestRelease = (XmlElement)releases.SelectSingleNode("release[starts-with(version,'" + api + "')]");

                                if (latestRelease != null)
                                {
                                    XmlElement majorVersionNode = (XmlElement)latestRelease["version_major"];
                                    XmlElement patchVersionNode = (XmlElement)latestRelease["version_patch"];

                                    majorVersion = int.Parse(majorVersionNode.InnerText);
                                    patchVersion = int.Parse(patchVersionNode.InnerText);

                                    Console.WriteLine("The latest release (for api '{0}') is {1}.{2}", api, majorVersion, patchVersion);

                                    switch (increment)
                                    {
                                        case "major":
                                            {

                                                Console.WriteLine("Incrementing major version, setting patch back to 0.");

                                                majorVersion++;
                                                patchVersion = 0;

                                            }
                                            break;

                                        case "patch":
                                            {
                                                Console.WriteLine("Incrementing minor version.");

                                                patchVersion++;
                                            }
                                            break;

                                        default:
                                            {
                                                throw new ArgumentException(increment + " is not a valid increment. Valid increments are major,patch.", "increment");
                                            }

                                    }

                                    Console.WriteLine("Created new release (for api '{0}') as version {1}.{2}", api, majorVersion, patchVersion);
                                }

                                // Create the new element
                                releases.InsertBefore(releaseElement, releases.FirstChild);
                            }


                            // Calculate the version
                            string version = api + "-" + majorVersion + "." + patchVersion + "-" + stream;

                            if (build != "")
                            {
                                version += "-build" + build;
                            }

                            Console.WriteLine("This version is known as '{0}'",version);

                            releaseElement.SelectSingleNode("name").InnerText = name + " " + version;
                            releaseElement.SelectSingleNode("version").InnerText = version;
                            releaseElement.SelectSingleNode("tag").InnerText = version;
                            releaseElement.SelectSingleNode("version_patch").InnerText = patchVersion.ToString();
                            releaseElement.SelectSingleNode("version_major").InnerText = majorVersion.ToString();
                            releaseElement.SelectSingleNode("release_link").InnerText = url + "/" + api + "/" + name + "-" + version + ".html";

                            string dateStamp = ((long)(DateTime.UtcNow - new DateTime(1970, 1, 1)).TotalSeconds).ToString();

                            releaseElement.SelectSingleNode("date").InnerText = dateStamp;

                            //
                            // Process the .info file
                            //


                            string infoFilePath = folder + "\\" + name + ".info";
                            string infoFileBackup = LoadFile(infoFilePath);
                            string infoFile = infoFileBackup;

                            try
                            {

                                //
                                // Append the important odule information
                                //
                                infoFile += Environment.NewLine;
                                infoFile += Environment.NewLine;
                                infoFile += "; This information is purely for module updates" + Environment.NewLine;
                                infoFile += "project status url = \"" + url + "\"" + Environment.NewLine;
                                infoFile += "version = \"" + version + "\"" + Environment.NewLine;
                                infoFile += "project = \"" + name + "\"" + Environment.NewLine;
                                infoFile += "datestamp = \"" + dateStamp + "\"" + Environment.NewLine;
                                SaveFile(infoFilePath, infoFile);


                                string rootFilePath = Directory.GetCurrentDirectory() + "\\" + name + "\\" + api + "\\" + name + "-" + version;

                                string currentDirectoryBackup = Directory.GetCurrentDirectory();

                                //
                                // Generate Tar.gz
                                //

                                string tarFilePath = rootFilePath + ".tar.gz";

                                Console.WriteLine("Generating {0}", tarFilePath);

                                Directory.SetCurrentDirectory(folder);

                                CreateTar(tarFilePath, ".");
                                Directory.SetCurrentDirectory(currentDirectoryBackup);

                                string tarMD5 = MD5FileHash(tarFilePath).ToLower();

                                Console.WriteLine("MD5 of {0} is {1}", tarFilePath, tarMD5);

                                XmlElement tarFileNode = (XmlElement)releaseElement["files"].ChildNodes[0];

                                tarFileNode["url"].InnerText = url + "/" + api + "/" + name + "-" + version + ".tar.gz";
                                tarFileNode["archive_type"].InnerText = "tar.gz";
                                tarFileNode["md5"].InnerText = tarMD5;
                                tarFileNode["size"].InnerText = (new FileInfo(tarFilePath)).Length.ToString();
                                tarFileNode["filedate"].InnerText = dateStamp;

                                //
                                // This is also the default version
                                //

                                releaseElement.SelectSingleNode("download_link").InnerText = url + "/" + api + "/" + name + "-" + version + ".tar.gz";
                                releaseElement.SelectSingleNode("date").InnerText = dateStamp;
                                releaseElement.SelectSingleNode("mdhash").InnerText = tarMD5;
                                releaseElement.SelectSingleNode("filesize").InnerText = (new FileInfo(tarFilePath)).Length.ToString(); ;

                                //
                                // Generate Zip
                                //

                                string zipFilePath = rootFilePath + ".zip";

                                Console.WriteLine("Generating {0}", zipFilePath);

                                Directory.SetCurrentDirectory(folder);
                                CreateZip(zipFilePath, ".");
                                Directory.SetCurrentDirectory(currentDirectoryBackup);

                                string zipMD5 = MD5FileHash(zipFilePath).ToLower();

                                Console.WriteLine("MD5 of {0} is {1}", zipFilePath, zipMD5);

                                XmlElement zipFileNode = (XmlElement)releaseElement["files"].ChildNodes[1];

                                // First file
                                zipFileNode["url"].InnerText = url + "/" + api + "/" + name + "-" + version + ".zip";
                                zipFileNode["archive_type"].InnerText = "zip";
                                zipFileNode["md5"].InnerText = zipMD5;
                                zipFileNode["size"].InnerText = (new FileInfo(zipFilePath)).Length.ToString();
                                zipFileNode["filedate"].InnerText = dateStamp;


                                //
                                // Now process all out options
                                //

                                if (Recommended)
                                {
                                    Console.WriteLine("Setting major version {0} as the recommended version.", majorVersion);

                                    project["recommended_major"].InnerText = majorVersion.ToString();
                                }

                                if (Supported)
                                {
                                    Console.WriteLine("Setting major version {0} as the supported version.", majorVersion);

                                    project["supported_majors"].InnerText = majorVersion.ToString();
                                }

                                if (Default)
                                {
                                    Console.WriteLine("Setting major version {0} as the default version.", majorVersion);

                                    project["default_major"].InnerText = majorVersion.ToString();
                                }


                                // Set the type
                                releaseElement["terms"]["term"]["value"].InnerText = type;

                                Console.WriteLine("Saving modified XML to '{0}'", xmlPath);

                                // Save the old XML back                    
                                xml.Save(xmlPath);


                                //
                                // Generate the HTML Release notes
                                //

                                XPathDocument myXPathDoc = new XPathDocument(xmlPath);
                                XslCompiledTransform myXslTrans = new XslCompiledTransform();

                                SaveFile("manifest_temp.xsl", Resources.manifest);

                                myXslTrans.Load("manifest_temp.xsl");

                                using (XmlTextWriter myWriter = new XmlTextWriter(rootFilePath + ".html", null))
                                {
                                    myXslTrans.Transform(myXPathDoc, null, myWriter);
                                }


                                File.Delete("manifest_temp.xsl");

                                Console.WriteLine("Release notes saved to {0}", rootFilePath + ".html");

                                
                            }
                            catch
                            {
                                throw;
                            }
                            finally
                            {
                                // Put the old info file back
                                SaveFile(infoFilePath, infoFileBackup);
                            }

                        }
                        break;



                    case "ssh":
                        {
                            // Let's shell out to an external system and run some commands.

                            if (Args.Length < 2)
                            {
                                NotEnoughArguments(command);
                                Environment.Exit(2);
                                return;
                            }

                            Console.WriteLine("");
                            Console.WriteLine("SSH ...");

                            //
                            // Parse the arguments
                            //

                            string address = Args[1].Trim();                            
                            string certificate = Args[2].Trim();

                            List<string> commands = new List<string>();

                            for (int i = 3; i < Args.Length; i++)
                            {
                                commands.Add(Args[i]);
                            }

                            //
                            // Break up the address into the correct components
                            //

                            string userNamePassword = address.Split('@')[0];
                            string host = address.Split('@')[1];

                            string user = userNamePassword.Split(':')[0];
                            string password = userNamePassword.Split(':')[1];

                            string censored = "";
                            foreach (char c in password)
                            {
                                censored += "*";
                            }



                            Console.WriteLine("Host      {0}",host);
                            Console.WriteLine("User      {0}", user);
                            Console.WriteLine("Password  {0}", censored);

                            SshShell ssh = null;

                            ssh = new SshShell(host, user, password);
                            ssh.RemoveTerminalEmulationCharacters = true;
                            ssh.Connect();

                            StringBuilder log = new StringBuilder();


                            // Sync with the other end
                            string guida = Guid.NewGuid().ToString();
                            string guidb = Guid.NewGuid().ToString();
                            string echo = String.Format("stty -icanon -echo; echo '{0}' '{1}'", guida, guidb);
                            ssh.WriteLine(echo);
                            // The command will be echoed once                            
                            // The result  will be echoed once
                            log.Append(ssh.Expect(guida + " " + guidb));

                            

                            foreach (string c in commands)
                            {
                                Console.WriteLine("Sending '{0}'",c);
                                
                                // TSend the command
                                //ssh.ExpectPattern = c;
                                ssh.ExpectPattern = "";
                                ssh.WriteLine(c);

                                // The command will be echoed once
                                //log.Append(ssh.Expect());
                                

                                //ssh.ExpectPattern = "";
                                // Send a newline to kick off the command
                                //ssh.WriteLine("");

                                //Console.WriteLine("Sent new line");


                                
                                // New Guid
                                guida = Guid.NewGuid().ToString();
                                guidb = Guid.NewGuid().ToString();
                                // Now we want to capure the rest
                                //ssh.ExpectPattern = "echo " + guid;
                                ssh.ExpectPattern =  guida + " " + guidb;
                                echo = String.Format("echo '{0}' '{1}'", guida, guidb);
                                ssh.WriteLine(echo);

                                string result = ssh.Expect();
                                log.Append(result);


                                Console.WriteLine("");
                                Console.WriteLine("--- command start ---");
                                Console.WriteLine("{0}", c);
                                Console.WriteLine("---  command end  ---");
                                Console.WriteLine("--- result start ---");
                                // Start result
                                //result = result.Substring(1, result.Length - ("echo " + guid).Length - 1);
                                string[] linesRaw = result.Split('\n');
                                //Console.WriteLine("{0} lines", linesRaw.Length - 1);
                                for (int i = 0; i < linesRaw.Length - 2; i++)
                                {
                                    Console.WriteLine("{0:0000} {1}", i, linesRaw[i]);
                                }
                                // end result
                                Console.WriteLine("---  result end  ---");


                            }

                            if (LogConversation)
                            {

                                Console.WriteLine("");
                                Console.WriteLine("");
                                Console.WriteLine("----- log start ----");
                                Console.WriteLine("{0}", log.ToString());
                                Console.WriteLine("----- log end ----");
                            }
                            ssh.Close();

                        }
                        break;


                    default:
                        {
                            Console.WriteLine("");
                            Console.WriteLine("Unknown command '{0}'", command);
                            Console.WriteLine("");

                            KnownCommands();

                        }
                        break;
                }
            }
            catch (Exception e)
            {
                Console.WriteLine("------------------------------------------------");
                Console.WriteLine("Error {0}", e.Message);

                if (ExitCleanOnError)
                {
                    Console.WriteLine("Because you specified --exitcleanonerror we will exit with a 0 to avoid arousing any unwanted attention.");
                    // Pretend the exit is good
                    Environment.Exit(0);
                }
                else
                {
                    // Bad exit
                    Environment.Exit(1);

                }
                return;
            }

            // Good exit
            Environment.Exit(0);
            return;

        }
    }
}
