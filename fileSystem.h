/* @file fileSystem.h
 *  @brief Emulates a basic file system.
 *  
 *  This file contains all structures and function prototypes for emulation of
 *  a basic UNIX-type file system. Re-written from Dr. Reichherzer's source
 *  code.
 *
 *  @author Aurburn Jones
 *  @author Derrick Masters
 *  @date 12/03/2019
 *  @info Course COP 4634
 *  @bug No known bugs.
 */

#ifndef FILESYSTEM_H
#define FILESYSTEM_H

    /* ---------- Includes ---------- */

    /* Standard I/O library */
    #include <stdio.h>

    /* Standard library */
    #include <stdlib.h>

    /* Standard symbolic library */
    #include <unistd.h>

    /* Standard string library */
    #include <string.h>

    /* Disk funtions header */
    #include "disk.h"

    /* Superblock functions header */
    #include "superBlock.h"

    /* ---------- Structures ---------- */
    
    // Data structure which serves as the file descriptor of the file system
    typedef struct fd{

        int inodeBlockNum;
        int fileptr;

    }fd_t;

    /* ---------- Prototypes ---------- */

    /** @brief Formats the virtual disk.
     *
     *  More detailed explanation...
     *
     *  @param diskSizeInKB - Size of the virtual disk in KB.
     *  @param path - Path of the virtual disk.
     *  @return -1 if an error occurs.
     */
    int format(int diskSizeInKB, char *path);

    /** @brief Opens file with the specified name and returns a file
     *         descriptor.
     *
     *  More detailed explanation...
     *
     *  @param name - Name of the file to be opened.
     *  @return NULL if an error occurs, file descriptor otherwise.
     */
    fd_t *openf(char *name);

    /** @brief Closes the file given by the file descriptor.
     *
     *  More detailed explanation...
     *
     *  @param stream - File descriptor indicating the file to be closed.
     *  @return -1 if an error occurs.
     */
    int closef(fd_t *stream);

    /** @brief Reads data from a file stream and stores them at the specified
     *         location.
     *
     *  More detailed explanation...
     *
     *  @param stream - The file stream to be read.
     *  @param data - The buffer to store data in.
     *  @param size - Number of bytes to be read.
     *  @return -1 if an error occurs or 0 if read successfully.
     */
    int readf(fd_t *stream, char *data, int size);

    /** @brief Writes data to a file stream given a file descriptor and data to
     *         be written.
     *
     *  More detailed explanation...
     *
     *  @param stream - The file stream to be appended.
     *  @param data - The buffer with data to be written to file.
     *  @param size - Number of bytes to be written.
     *  @return -1 if an error occurs or 0 if written successfully.
     */
    int writef(fd_t *stream, char *data, int size);

#endif /* FILESYSTEM_H */

