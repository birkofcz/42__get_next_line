/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openwrite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:26:07 by sbenes            #+#    #+#             */
/*   Updated: 2023/03/02 13:14:29 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
To learn how to open files, create them or write into them, read from them
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h> 

#define BUFFER_SIZE 4096

/*
Main:

fd = file descriptor saved as int;
|
fd = open file "testfile.txt with flags - see flags in other comment"
|
if fd - 1 == error message
|
printf fd
|
write into the file
|
if close == -1 - error message
|
read from a file into buff and of buffer_size (predifined);
|
prit the buffer with read content
|
print number of bytes read
|
return (0)
*/

int main(void)
{
	int fd;
	int bytes_read;
	FILE *fp;
	char buff[BUFFER_SIZE + 1];

	fd = open("testfile.txt", O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
	if (fd == -1)
	{
		printf("open() error\n");
		return (1);
	}
	printf("%d\n", fd);
	
	write(fd, "Hello world!\n", 14);

	fd = open("testfile.txt", O_RDONLY);
	bytes_read = read(fd, buff, BUFFER_SIZE);
	buff[bytes_read] = '\0';
	printf("%s", buff);
	printf("%d\n", bytes_read);
	close(fd);
	
	return (0);
}

/*
-- FLAGS --
The flags parameter in the open() function in C specifies how the file should be opened. Here is a list of common flags and their descriptions:

O_RDONLY - Open for reading only.
O_WRONLY - Open for writing only.
O_RDWR - Open for reading and writing.
O_CREAT - Create the file if it does not exist.
O_TRUNC - Truncate the file if it already exists.
O_APPEND - Append to the end of the file if it already exists.
O_EXCL - Fail if the file already exists.
O_NONBLOCK - Set non-blocking mode.
O_SYNC - Write data to the file synchronously.
O_DSYNC - Write data to the file synchronously, but only for the data and not the metadata.
O_RSYNC - Read data from the file synchronously.
O_NOCTTY - Do not make the file the controlling terminal for the process.
O_DIRECTORY - The file must be a directory.
O_TMPFILE - Create an unnamed temporary file.
O_CLOEXEC - Close the file descriptor when executing a new program with exec.
These flags can be combined using the bitwise OR operator |. For example, O_CREAT | O_WRONLY | O_TRUNC will open a file for writing, create it if it does not exist, and truncate it if it already exists.

 -- S_FLAGS -- 
The flags starting with S_ are file mode flags that specify the permissions of a new file or directory created with the open() or mkdir() functions in C. They are typically used in combination with the O_CREAT flag, which creates a new file if it does not already exist.

Here are the S_ flags and their meanings:

S_IRUSR: Read permission for the owner of the file.
S_IWUSR: Write permission for the owner of the file.
S_IXUSR: Execute (or search) permission for the owner of the file.
S_IRGRP: Read permission for the group owner of the file.
S_IWGRP: Write permission for the group owner of the file.
S_IXGRP: Execute (or search) permission for the group owner of the file.
S_IROTH: Read permission for other users.
S_IWOTH: Write permission for other users.
S_IXOTH: Execute (or search) permission for other users.
These flags are used in combination with octal numbers to specify the file permissions. For example, 0644 gives the file owner read and write permission, and all other users read permission. This is equivalent to S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH.

To set the file permissions of a new file or directory, you can combine the O_CREAT flag with the appropriate S_ flags using the bitwise OR operator (|). For example, open("myfile.txt", O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR) creates a new file called myfile.txt with read and write permission for the file owner.
*/