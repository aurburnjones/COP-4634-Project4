/** @file disk.c
 *  @brief Simulates a physical disk; reads and writes blocks of data.
 *  
 *  This file contains all function definitions for simulating all basic
 *  operation of the virtual disk used by the UNIX-type filesystem. Re-written
 *  from Dr. Reichherzer's source code.
 *
 *  @author Aurburn Jones
 *  @author Michael Wagner
 *  @date 12/03/2019
 *  @info Course COP 4634
 *  @bug No known bugs.
 */

/* ---------- Includes ---------- */

/* Disk functions header */
#include "disk.h"

/* ---------- Definitions ---------- */

// Local definition of the maximum number of data blocks
#define NUM_BLOCKS 1

/* ---------- Functions ---------- */

/** @brief Constructs a disk simulated by a file.
 *
 *  More detailed explanation...
 *
 *  @param sizeInKB - Size of the disk to be created in kilobytes.
 *  @param path - Path of the file simulating the disk.
 *  @return -1 if an error occurs or 0 if created successfully.
 */
int createDisk(int sizeInKB, const char *path){

    if(sizeInKB <= 0){

        strncpy(errorDesc, "Invalid disk size\n", ERROR_MESSAGE_SIZE);
        return -1;

    }

    _sizeInKB = sizeInKB;
    _physicalDisk = fopen(path, "w+");

    if(_physicalDisk == NULL){

        strncpy(errorDesc, "Failed to create file\n", ERROR_MESSAGE_SIZE);
        return -1;

    }

    _diskLength = sizeInKB * BLOCK_SIZE;

    return 0;

}

/** @brief Reads a data block from the disk.
 *
 *  More detailed explanation...
 *
 *  @param blockNumber - Indicates the number (ID) of the block to be read.
 *  @param blockData - Block of data the size of BLOCK_SIZE.
 *  @return -1 if an error occurs, else the number of bytes read.
 */
int readBlock(int blockNumber, char *blockData){

    int error = 0;
    int count = 0;

    if((blockNumber >= _sizeInKB) || (blockNumber < 0)){

        strncpy(errorDesc, "Invalid block number\n", ERROR_MESSAGE_SIZE);
        return -1;

    }

    // Offset specified number of bytes from the beginning of the disk
    error = fseek(_physicalDisk, blockNumber * BLOCK_SIZE, 0);

    if(error != 0){

        strncpy(errorDesc, "Couldn't seek to specified block\n", ERROR_MESSAGE_SIZE);
        return -1;

    }

    // Read NUM_BLOCKS units of 1024 bytes from file _physicalDisk to array blockData
    count = fread(blockData, BLOCK_SIZE, NUM_BLOCKS, _physicalDisk);

    if(count != NUM_BLOCKS){

        strncpy(errorDesc, "Couldn't read block\n", ERROR_MESSAGE_SIZE);
        return -1;

    }

    return error;

}

/** @brief Writes the data block to the disk.
 *
 *  More detailed explanation...
 *
 *  @param blockNumber - Location of where the data block is to be written.
 *  @param blockData - Block of data to be written.
 *  @param numberOfBytes - Number of bytes to write into the block.
 *  @return -1 if an error occurs, else the number of bytes written.
 */
int writeBlock(int blockNumber, const char* blockData, int numberOfBytes){

    int error = 0;
    int count = 0;
    int len = 0;

    if((blockNumber >= _sizeInKB) || (blockNumber < 0)){

        strncpy(errorDesc, "Invalid block number\n", ERROR_MESSAGE_SIZE);
        return -1;

    }

    // Offset specified number of bytes from the beginning of the disk
    error = fseek(_physicalDisk, blockNumber * BLOCK_SIZE, 0);

    if(error != 0){

        strncpy(errorDesc, "Couldn't seek to specified block\n", ERROR_MESSAGE_SIZE);
        return -1;

    }

    // If number of bytes to write is larger than block, write maximum of a
    // block, else write number of bytes
    len = (numberOfBytes > BLOCK_SIZE ? BLOCK_SIZE : numberOfBytes);

    // Write len units of 1024 bytes from file _physicalDisk to array blockData
    count = fwrite(blockData, len, NUM_BLOCKS, _physicalDisk);

    if(count != NUM_BLOCKS){

        strncpy(errorDesc, "Couldn't write block\n", ERROR_MESSAGE_SIZE);
        return -1;

    }

    return error;

}

/** @brief Determines the size of the disk.
 *
 *  More detailed explanation...
 *
 *  @param void
 *  @return Size of the disk in kilobytes.
 */
int getSize(void){

    return _sizeInKB;

}

