# Cloning the ls(list) command using C

### Key topics

1. ## **Command Line Arguments**

   - _main(int argc, char \*argv[])_
   - Parsing option like **l**, **a**, **R** (long listing, show hidden files, recursive, etc.)
   - Functions: **strcmp**, **getopt** (optional for option parsing)

2. ## Working with directories

   - Functions
     - **opendir**, **readdir**, **closedir**
     - **struct dirent**
   - Handling "." and ".."

3. File Information (Metadata)

   -
   - Functions
     - **stat**, **lstat**, **fstat**
   - **struct stat** -> file size, permission, timestamps, etc.
   - Use macros like _S_ISDIR_, _S_ISREF_, etc.

4. File Permissions & Ownership

   -
   - Extracting permission from _struct stat (st_mode)_
   - Displaying rwx format (rw-r--r--)
   - Functions: getpwuid, getgrgid (to map UID/GID to names)

5. ## Time & Date Formatting

   - Use `st_mtime` from `struct stat`
   - Functions: `localtime`, `strftime`

6. ## Sorting & Formatting Output

   - Sorting files alphabetically (default)
   - Possibly by modification time (`t`)
   - Use `qsort` in C

7. ## Recursive Listing (R)

   - Recursively traverse directories
   - Carefully avoid infinite recursion with `"."` and `".."`

8. ## Error Handling

   - `perror`, `strerror(errno)`
   - Handle cases like: permission denied, non-existent directory

9. Extra Features (optional)
   -
   - Coloring output like `ls --color` (using ANSI escape codes)
   - Hard links (`st_nlink`)
   - File types: directory, symlink, socket, pipe, etc.

Scope of Work:

### 1. First make a simple version: list filenames (opendir + readdir).

### 2. Then add file info (`stat`)

### 3. Then formating (l, permissions, ownership)

### 4. Finally add recursion & sorting
