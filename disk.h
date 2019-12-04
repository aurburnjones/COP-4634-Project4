/** @file disk.h
 *  @brief Simulates a physical disk; reads and writes blocks of data.
 *  
 *  This file contains all global variables and function prototypes for
 *  simulating all basic operation of the virtual disk used by the UNIX-type
 *  filesystem. Re-written from Dr. Reichherzer's source code.
 *
 *  @author Aurburn Jones
 *  @author Derrick Masters
 *  @date 12/03/2019
 *  @info Course COP 4634
 *  @bug No known bugs.
 */

#ifndef DISK_H
#define DISK_H

    /* ---------- Includes ---------- */

    /* Standard I/O library */
    #include <stdio.h>

    /* Standard library */
    #include <stdlib.h>

    /* Standard symbolic library */
    #include <unistd.h>

    /* Standard string library */
    #include <string.h>

    /* Inode functions header */
    #include "inode.h"
    
    /* ---------- Definitions ---------- */
    
    // Global definition for the maximum block size
    #define BLOCK_SIZE 1024

    // Global definition for the maximum error message length
    #define ERROR_MESSAGE_SIZE 256

    /* ---------- Global variables ---------- */

    // Size of the virtual disk
    int _sizeInKB;

    // Length of data blocks of the virtual disk
    int _diskLength;

    // Pointer to the physical disk
    FILE *_physicalDisk;

    // Output message indicating the nature of an error
    char errorDesc[ERROR_MESSAGE_SIZE];

    /* ---------- Prototypes ---------- */

    /** @brief Constructs a disk simulated by a file.
     *
     *  More detailed explanation...
     *
     *  @param sizeInKB - Size of the disk to be created in kilobytes.
     *  @param path - Path of the file simulating the disk.
     *  @return -1 if an error occurs or 0 if created successfully.
     */
    int createDisk(int sizeInKB, const char *path);

    /** @brief Reads a data block from the disk.
     *
     *  More detailed explanation...
     *
     *  @param blockNumber - Indicates the number (ID) of the block to be read.
     *  @param blockData - Block of data the size of BLOCK_SIZE.
     *  @return -1 if an error occurs, else the number of bytes read.
     */
    int readBlock(int blockNumber, char *blockData);

    /** @brief Writes the data block to the disk.
     *
     *  More detailed explanation...
     *
     *  @param blockNumber - Location of where the data block is to be written.
     *  @param blockData - Block of data to be written.
     *  @param numberOfBytes - Number of bytes to write into the block.
     *  @return -1 if an error occurs, else the number of bytes written.
     */
    int writeBlock(int blockNumber, const char* blockData, int numberOfBytes);

    /** @brief Determines the size of the disk.
     *
     *  More detailed explanation...
     *
     *  @param void
     *  @return Size of the disk in kilobytes.
     */
    int getSize(void);

#endif /* DISK_H */

