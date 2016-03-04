````
USAGE: my_ls [OPTION]... [FILE]...

OPTIONS:
  -l	 Long list format.
  -m	 Stream output format. Display filenames on the same line separated by commas.
  -1	 Force output to be one entry per line. This is the default when output is not a terminal.
  -C	 Force multi column output. This is the default when output is a terminal.
  -R	 Recursive.
  -r	 Reverse sort order.
  -d	 Don't follow links given as arguments.
  -t	 Sort by modification time.
  -a	 Include hidden files.
  -A	 Include hidden files except '.' and '..'.
  -L	 Dereference symbolic links.
  -G	 Colorize output.
  -g	 Print group name (long list format without owner name).
  -f	 Don't sort output. This option turns on the -a option.
  -F	 Display file type symbols after filenames (/ for directories, @ for symbolic links, etc...).
  -h	 Use human readable file sizes in long list format.
  --help Print help
````


A minimal `ls` implementation using only a few functions from the standard library:

`opendir`, `readdir`, `closedir`, `stat`, `lstat`, `getpwuid`, `getgrgid`, `time`, `ctime`, `readlink`, `getopt`, `malloc`, `free`
