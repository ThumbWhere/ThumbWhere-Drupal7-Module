using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Configuration.Install;   
using Microsoft.Win32;
using System.Linq;
using System.IO;


namespace DrupalUtil
{

    /// <summary>
    /// Implements Custom install step that will change the System wide path to include this application.
    /// </summary>
    [RunInstaller(true)]
    public partial class DrupalUtilInstaller : System.Configuration.Install.Installer
    {

        
        /// <summary>
        /// Called during install
        /// </summary>
        /// <param name="stateSaver"></param>
        public override void Install(System.Collections.IDictionary stateSaver)
        {
            base.Install(stateSaver);
            
            string curPath = GetPath();

            //using (StreamWriter log = File.CreateText(curPath + "install.log"))
            {
                //log.WriteLine("started = {0}", DateTime.Now.ToString());
                //log.WriteLine("curPath = {0}", curPath);
                

                stateSaver.Add("previousPath", curPath);
                string newPath = AddPath(curPath, MyPath());

                //log.WriteLine("newPath = {0}", newPath);

                if (curPath != newPath)
                {
                    //log.WriteLine("Adding new path");

                    stateSaver.Add("changedPath", true);
                    SetPath(newPath);
                }
                else
                {
                    //log.WriteLine("Not adding");

                    stateSaver.Add("changedPath", false);
                }

                //log.WriteLine("completed = {0}", DateTime.Now.ToString());
                //log.Close();
            }
        }

        /// <summary>
        /// Called during uninstall
        /// </summary>
        /// <param name="savedState"></param>
        public override void Uninstall(System.Collections.IDictionary savedState)
        {
            base.Uninstall(savedState);
            if ((bool)savedState["changedPath"])
                SetPath(RemovePath(GetPath(), MyPath()));
        }

        /// <summary>
        /// Called during rollback
        /// </summary>
        /// <param name="savedState"></param>
        public override void Rollback(System.Collections.IDictionary savedState)
        {
            base.Rollback(savedState);
            if ((bool)savedState["changedPath"])
                SetPath((string)savedState["previousPath"]);
        }

        /// <summary>
        /// Get the file path for the executing assembly
        /// </summary>
        /// <returns></returns>
        private static string MyPath()
        {
            string myFile = System.Reflection.Assembly.GetExecutingAssembly().Location;
            string myPath = System.IO.Path.GetDirectoryName(myFile);
            return myPath;
        }


        /// <summary>
        /// Get the Path registry key
        /// </summary>
        /// <param name="writable"></param>
        /// <returns></returns>
        private static RegistryKey GetPathRegKey(bool writable)
        {
            // for the user-specific path...
            //return Registry.CurrentUser.OpenSubKey("Environment", writable);

            // for the system-wide path...
            return Registry.LocalMachine.OpenSubKey(@"SYSTEM\CurrentControlSet\Control\Session Manager\Environment", writable);
        }

        /// <summary>
        /// Set the path registry key value
        /// </summary>
        /// <param name="value"></param>
        private static void SetPath(string value)
        {
            using (RegistryKey reg = GetPathRegKey(true))
            {
                reg.SetValue("Path", value, RegistryValueKind.ExpandString);
            }
        }

        // Get the path registry key value
        private static string GetPath()
        {
            using (RegistryKey reg = GetPathRegKey(false))
            {
                return (string)reg.GetValue("Path", "", RegistryValueOptions.DoNotExpandEnvironmentNames);
            }
        }

        /// <summary>
        /// Add a path to an existing path
        /// </summary>
        /// <param name="list"></param>
        /// <param name="item"></param>
        /// <returns></returns>
        private static string AddPath(string list, string item)
        {
            List<string> paths = new List<string>(list.Split(';'));

            foreach (string path in paths)
                if (string.Compare(path, item, true) == 0)
                {
                    // already present
                    return list;
                }

            paths.Add(item);
            return string.Join(";", paths.ToArray());
        }

        /// <summary>
        /// Remove a path from the existing path
        /// </summary>
        /// <param name="list"></param>
        /// <param name="item"></param>
        /// <returns></returns>
        private static string RemovePath(string list, string item)
        {
            List<string> paths = new List<string>(list.Split(';'));

            for (int i = 0; i < paths.Count; i++)
                if (string.Compare(paths[i], item, true) == 0)
                {
                    paths.RemoveAt(i);
                    return string.Join(";", paths.ToArray());
                }

            // not present
            return list;
        }
    }    
}
