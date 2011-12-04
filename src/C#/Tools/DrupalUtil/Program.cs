using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Xml;
using System.IO;

namespace DrupalUtil
{
    class Program
    {

        static void KnownCommands()
        {
            Console.WriteLine("Known commands");
            Console.WriteLine("");

            Usage("new");

        }

        static void Usage(string command)
        {

            switch (command.ToLower())
            {
                case "new":
                    {
                        Console.WriteLine("new - Creates a new module");
                        Console.WriteLine("");
                        Console.WriteLine("new name maintainer api_version description");
                        Console.WriteLine("");
                        Console.WriteLine("eg: new guitar memyselfandi 7.x http://example.com/release-info/  ");
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

        static void NotEnoughArguments(string command)
        {
            Console.WriteLine("Not enough arguments.");
            Console.WriteLine("");
            Console.WriteLine("Here is the correct usage of '{0}'", command);
            Console.WriteLine("");
            Console.WriteLine("-----------------------------------------");
            Console.WriteLine("");

            Usage(command);
        }


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

                        XmlDocument xml = new XmlDocument();
                        xml.LoadXml(Resources.manifest_template);

                        XmlNamespaceManager xmlnsManager = new System.Xml.XmlNamespaceManager(xml.NameTable);

                        //Add the namespaces used in books.xml to the XmlNamespaceManager.
                        xmlnsManager.AddNamespace("dc", "http://purl.org/dc/elements/1.1/");                        


                        xml.SelectSingleNode("project/title").InnerText = name;
                        xml.SelectSingleNode("project/short_name").InnerText = name;                        
                        xml.SelectSingleNode("project/dc:creator", xmlnsManager).InnerText = maintainer;
                        xml.SelectSingleNode("project/link").InnerText = url + "/" + name + "/";

                        // Clear our any release information
                        xml.SelectSingleNode("project/releases").RemoveAll();

                        //
                        // Create the new module
                        //

                        Directory.CreateDirectory("release-history");
                        Directory.CreateDirectory("release-history/" + name);
                        Directory.CreateDirectory("release-history/" + name + "/" + api_version);

                        string xmlPath = "release-history/" + name + "/" + api_version + "/manifest.xml";

                        if (File.Exists(xmlPath))
                        {
                            Console.WriteLine("There is already a manifest file at '{0}'", xmlPath);
                        }

                        // Save the XML
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
