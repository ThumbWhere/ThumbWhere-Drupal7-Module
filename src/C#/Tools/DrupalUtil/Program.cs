using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Xml;
using System.IO;
using System.Security.Cryptography;

namespace DrupalUtil
{
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
            Console.WriteLine("Known commands: help,new,add");
            Console.WriteLine("");

            Usage("new");
            Usage("help");

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
                        Console.WriteLine("new name maintainer api_version description");
                        Console.WriteLine("");
                        Console.WriteLine("eg: new guitar memyselfandi 7.x http://example.com/release-history/");
                    }
                    break;


                case "add":
                    {

                        Console.WriteLine("add - Adds a release to the manifest.");
                        Console.WriteLine("");
                        Console.WriteLine("add folder name api_version increment");
                        Console.WriteLine("");
                        Console.WriteLine(@"eg: add C:\work\hard\  guitar 7.x major  (will increment the major version number)");
                        Console.WriteLine(@"eg: add C:\work\easy\  guitar 7.x minor  (will increment the minor version number)");
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
        /// Returns the SHA256 File Hash from a passed full file path
        /// </summary>
        /// <param name="p_file_path">The full path of the file</param>
        /// <returns>an SHA256 Hash as a string</returns>
        static public string SHA256FileHash(string p_file_path)
        {
            SHA256CryptoServiceProvider l_csp = new SHA256CryptoServiceProvider();

            // compute hash
            using (FileStream l_stream = File.Open(p_file_path, FileMode.Open, FileAccess.Read, FileShare.Read))
            {
                byte[] l_hash = l_csp.ComputeHash(l_stream);
                l_stream.Close();

                return Bytes2Hex(l_hash);
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
        /// Main entry point
        /// </summary>
        /// <param name="args"></param>
        static void Main(string[] args)
        {

            

            if (args.Length == 0)
            {
                Console.WriteLine("UsageDrupalUtil.exe COMMAND ARGUMENTS");
                Console.WriteLine("By James Mc Parlane 2011 james@thumbwhere.com");
                Console.WriteLine("");
                KnownCommands();
                Environment.Exit(-1);
                return;
            }


            string command = args[0];

            switch (command.ToLower())
            {
                case "help":
                    {

                        if (args.Length < 1)
                        {
                            NotEnoughArguments(command);
                            Environment.Exit(-2);
                            return;
                        }


                        if (args.Length == 2)
                        {
                            // Help on a specific comand
                            Usage(args[1]);
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

                        if (args.Length < 5)
                        {
                            NotEnoughArguments(command);
                            Environment.Exit(-2);
                            return;
                        }

                        Console.WriteLine("");
                        Console.WriteLine("Creating new Module...");

                        //
                        // Parse the arguments
                        //

                        string name = args[1].Trim();
                        string maintainer = args[2].Trim();
                        string api_version = args[3].Trim();
                        string url = args[4].Trim();
                        


                        Console.WriteLine("");
                        Console.WriteLine("name         = '{0}'", name);
                        Console.WriteLine("maintainer   = '{0}'", maintainer);
                        Console.WriteLine("api_version  = '{0}'", api_version);
                        Console.WriteLine("url          = '{0}'", url);
                        
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

                        // Clear our any release information
                        xmlTemplate.SelectSingleNode("project/releases").RemoveAll();

                        //
                        // Create the new module
                        //
                        
                        Directory.CreateDirectory(name);
                        Directory.CreateDirectory(name + "/" + api_version);

                        string xmlPath = name + "/" + api_version + "/manifest.xml";

                        if (File.Exists(xmlPath))
                        {
                            Console.WriteLine("There is already a manifest file at '{0}'", xmlPath);
                        }

                        // Save the XML
                        xmlTemplate.Save(xmlPath);
                        

                    }
                break;

                case "add":
                {
                    if (args.Length < 5)
                    {
                        NotEnoughArguments(command);
                        Environment.Exit(-2);
                        return;
                    }

                    Console.WriteLine("");
                    Console.WriteLine("Adding new release...");

                    //
                    // Parse the arguments
                    //

                    string folder = args[1].Trim();
                    string name = args[2].Trim();                    
                    string api_version = args[3].Trim();                    
                    string increment = args[4].Trim();



                    Console.WriteLine("");

                    Console.WriteLine("folder           = '{0}'", folder);
                    Console.WriteLine("name             = '{0}'", name);
                    Console.WriteLine("api_version      = '{0}'", api_version);
                    Console.WriteLine("increment        = '{0}'", increment);

                    Console.WriteLine("");

                    string xmlPath = name + "/" + api_version + "/manifest.xml";
                    Console.WriteLine("Loading XML from    {0}", xmlPath);

                    // Get the current manifest
                    XmlDocument xml = new XmlDocument();
                    xml.Load(xmlPath);

                    // Load the current template
                    XmlDocument xmlTemplate = new XmlDocument();
                    xmlTemplate.LoadXml(Resources.manifest_template);
                    XmlNamespaceManager xmlnsManager = new System.Xml.XmlNamespaceManager(xmlTemplate.NameTable);

                    string majorVersion = "M";
                    string minorVersion = "m";

                    // Create the new element
                    XmlElement releaseElement = (XmlElement)xml.SelectSingleNode("project/releases").AppendChild(xml.CreateElement("release"));

                    // Populate it
                    releaseElement.InnerXml = xmlTemplate.SelectSingleNode("project/releases/release").InnerXml;

                    // Calculate the version
                    string version = api_version + "-" + majorVersion + "." + minorVersion;


                    releaseElement.SelectSingleNode("name").InnerText = name + " " + version;
                    releaseElement.SelectSingleNode("version").InnerText =  version;
                    
                    // Save the old XML back                    
                    xml.Save(xmlPath);

                }
                break;


                default:
                {
                    Console.WriteLine("");
                    Console.WriteLine("Unknown command '{0}'",command);
                    Console.WriteLine("");

                    KnownCommands();

                }
                break;
            }
        }
    }
}
