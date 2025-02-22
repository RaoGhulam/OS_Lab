# Basic Commands

1. `mkdir` – Creates a new directory.
   - Example: `mkdir new_directory`

2. `rm` – Removes a specified file or directory.
   - Example: `rm file.txt` (removes a file)
   - Example: `rm -r directory_name` (removes a directory and its contents)

3. `cd` – Changes the current working directory.
   - Example: `cd /path/to/directory`

4. `ls` – Lists the files and directories in the current directory.
   - Example: `ls`
   - Example: `ls -l` (lists in long format with details)

5. `cat` – Displays the contents of a file.
   - Example: `cat file.txt`

6. `touch` – Creates an empty file or updates the timestamp of an existing file.
   - Example: `touch new_file.txt`

7. `sudo` – Executes a command with superuser privileges.
   - Example: `sudo apt update` (runs `apt update` with superuser privileges)

8.  `gedit` – Opens the default text editor in a graphical interface.
   - Example: `gedit file.txt`

# Security and Network

1. `sudo ufw status` – Check Firewall status
2. `hostname -I` – Check Local IP Address

# System Information

1. `lscpu` – Display detailed information about the CPU.
2. `free -h` – Display total, used and free memory in a human-readable format.
3. `upower -i $(upower -e | grep BAT)` – Provides detailed information about the battery status. 

# APT Package Manager
   
   `apt` – Manages packages (installation, removal, updates) on Debian-based systems.
   - Example: `sudo apt update` (updates the package lists for upgrades)
   - Example: `sudo apt upgrade` (upgrades all installed packages to the latest version)
   - Example: `sudo apt install package_name` (installs a package)
   - Example: `sudo apt remove package_name` (removes a package)
   - Example: `sudo apt purge package_name` (removes a package and its configuration files)
   - Example: `sudo apt autoremove` (removes unnecessary packages that were installed as dependencies)
   - Example: `sudo apt autoclean` (removes obsolete package files from the cache)




# Install C and C++ Compilers (other essential too)
```bash
    sudo apt install build-essential
```

Compile and Execute the C++ Program
```bash
    g++ program.cpp -o program
    ./program
```




# wget
It is a command-line utility used to download files from the web. It supports downloading files using HTTP, HTTPS, and FTP protocols.

Here's a basic example:
```bash
    wget https://example.com/file.zip
```
By default, wget will download the file to the current directory. It also has various options for controlling things like download speed, file renaming, and retries for failed downloads.

If wget is not installed by default on your system, you can install it using the following command:
```bash
    sudo apt install wget
```






# Install Chrome on Ubuntu

### Method 1: Manually Download and Install the .deb File

1. First, download the latest `.deb` file for Google Chrome using `wget`:
    ```bash
    wget https://dl.google.com/linux/direct/google-chrome-stable_current_amd64.deb
    ```

2. Install the .deb file with apt (automatically handles dependencies):
    ```bash
    sudo apt install ./google-chrome-stable_current_amd64.deb
    ```

3. Remove the .deb file (Optional):
   ```bash
   rm google-chrome-stable_current_amd64.deb
    ```

### Method 2: Adding the Official Google Chrome Repository for Automatic Updates via APT

1. Use `wget` to download the Google signing key:
   Note: The GPG key will be stored in /usr/share/keyrings/.
    ```bash
    wget -q -O - https://dl.google.com/linux/linux_signing_key.pub | sudo gpg --dearmor -o /usr/share/keyrings/google-chrome.gpg
    ```

2.  Now, add the Google Chrome repository to your sources list:

    **Note:**  
    - The repository URL will be stored in `/etc/apt/sources.list.d/`.  
    - The file containing the repository URL will be deleted if you use `sudo apt purge <package_name>`.  

    ```bash
    echo "deb [arch=amd64 signed-by=/usr/share/keyrings/google-chrome.gpg] http://dl.google.com/linux/chrome/deb/ stable main" | sudo tee /etc/apt/sources.list.d/google-chrome.list
    ```

3. After adding the repository, update the `apt` package index:
    ```bash
    sudo apt update
    ```

4. Now, you can install or upgrade Google Chrome using `apt`:
    ```bash
    sudo apt install google-chrome-stable
    ```

# Install VS Code

1. Use `wget` to download the VS Code signing key:
    ```bash
    wget -qO- https://packages.microsoft.com/keys/microsoft.asc | sudo gpg --dearmor -o /usr/share/keyrings/microsoft.gpg
    ```

2.  Now, add the VS Code repository to your sources list:
   
    **Note:**  
    - The repository URL will be stored in `/etc/apt/sources.list.d/`.  
    - The file containing the repository URL will be deleted if you use `sudo apt purge <package_name>`.
  
    ```bash
    echo "deb [arch=amd64 signed-by=/usr/share/keyrings/microsoft.gpg] https://packages.microsoft.com/repos/code stable main" | sudo tee /etc/apt/sources.list.d/vscode.list
    ```

3. After adding the repository, update the `apt` package index:
    ```bash
    sudo apt update
    ```

4. Now, you can install or upgrade VS Code using `apt`:
    ```bash
    sudo apt install code
    ```
