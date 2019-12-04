/** @file fileSystem.c
 *  @brief Emulates a basic file system.
 *  
 *  This file contains all function definitions for emulation of a basic
 *  UNIX-type file system. Re-written from Dr. Reichherzer's source code.
 *
 *  @author Aurburn Jones
 *  @author David Warren
 *  @date 12/09/2018
 *  @info Course COP 4634
 *  @bug No known bugs.
 */

/* ---------- Includes ---------- */

/* File system functions */
#include "fileSystem.h"

/* ---------- Unknown Prototypes ---------- */

void readSuperBlock(superBlock_t *superBlock);
void writeSuperBlock(superBlock_t *superBlock);
void readInode(inode_t *inode, int blockNumber);
void writeInode(inode_t *inode, int blockNumber);
void printInodes(void);
void printFreeBlocks(void);
void intToByteArray(int value, char *buffer, int pos);
int byteArrayToInt(char *buffer, int pos);

/* ---------- Functions ---------- */

/** @brief A test program for testing file system operations.
 *
 *  More detailed explanation...
 *
 *  @param argCount - The number of incoming arguments.
 *  @param argVector - An array of incoming arguments.
 *  @return 0
 */
int main(int argCount, char **argVector){

    int error = 0;

    error = format(100, "./disk1.bin");

    return 0;

}

/** @brief Formats the virtual disk.
 *
 *  More detailed explanation...
 *
 *  @param diskSizeInKB - Size of the virtual disk in KB.
 *  @param path - Path of the virtual disk.
 *  @return -1 if an error occurs.
 */
int format(int diskSizeInKB, char *path){

    int error = 0;

    // Create a disk
    error = createDisk(diskSizeInKB, path);

    /*
     * Complete implementation of this function.
     * Must use the function read/writeSuperBlock() & read/writeInode().
     * Formatting requires that you setup the superblock, write empty inodes,
     * and setup your free list for the remaining blocks.
     */

    return error;

}

/** @brief Opens file with the specified name and returns a file
 *         descriptor.
 *
 *  More detailed explanation...
 *
 *  @param name - Name of the file to be opened.
 *  @return NULL if an error occurs, file descriptor otherwise.
 */
fd_t *openf(char *name){

    return NULL;

}

/** @brief Closes the file given by the file descriptor.
 *
 *  More detailed explanation...
 *
 *  @param stream - File descriptor indicating the file to be closed.
 *  @return -1 if an error occurs.
 */
int closef(fd_t *stream){

    return -1;

}

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
int readf(fd_t *stream, char *data, int size){

    return -1;

}

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
int writef(fd_t *stream, char *data, int size){

    return -1;

}

/* ---------- Unknown Functions ---------- */

/** @brief Reads the superblock from disk.
 *
 *  More detailed explanation...
 *
 *  @param superBlock - Destination to read the disk's superblock.
 *  @return void
 */
void readSuperBlock(superBlock_t *superBlock){

    int error = 0;
    int numDiskBlocks = 0;
    int numInodes = 0;
    char buffer[BLOCK_SIZE] = {'\0'};

    // Read block and convert it to the superblock
    error = readBlock(0, buffer);

    // Read number of disk blocks from block
    numDiskBlocks = byteArrayToInt(buffer, 0);

    // Read number of inodes from block
    numInodes = byteArrayToInt(buffer, 4);

    // Read start of free block to disk
    

    // Finish implementing this function


    return;

}

/** @brief Writes the superblock to disk.
 *
 *  More detailed explanation...
 *
 *  @param superBlock - Destination to store the disk's superblock.
 *  @return void
 */
void writeSuperBlock(superBlock_t *superBlock){

    char buffer[BLOCK_SIZE] = {'\0'};

    // Write number of disk blocks into buffer
    intToByteArray(superBlock->numberOfDiskBlocks, buffer, 0);

    // Write number of inodes into buffer
    intToByteArray(superBlock->numberOfInodes, buffer, 4);

    // Finish this function
    

    return;

}

/** @brief Reads an inode from disk.
 *
 *  More detailed explanation...
 *
 *  @param inode - The inode to be read.
 *  @param blockNumber - The block number (ID) that holds the inode to be read.
 *  @return void
 */
void readInode(inode_t *inode, int blockNumber){

    int error = 0;
    char block[BLOCK_SIZE] = {'\0'};

    // Read block containing the inode
    error = readBlock(blockNumber, block);

    // Finish implementing this method


    return;

}

/** @brief Writes an inode to disk.
 *
 *  More detailed explanation...
 *
 *  @param inode - The inode to be written to the disk.
 *  @param blockNumber - The block number (ID) to which the inode will be written.
 *  @return void
 */
void writeInode(inode_t *inode, int blockNumber){

    // Implement this function
    

    return;

}

/** @brief Prints the contents of the inodes of the virtual disk to the screen.
 *
 *  More detailed explanation...
 *
 *  @param void
 *  @return void
 */
void printInodes(void){

    // Implement this function
    

    return;

}

/** @brief Prints the block numbers (IDs) of the disk blocks that are free.
 *
 *  More detailed explanation...
 *
 *  @param void
 *  @return void
 */
void printFreeBlocks(void){

    // Implement this function


    return;

}

/** @brief Writes an integer to a byte array.
 *
 *  More detailed explanation...
 *
 *  @param value - The integer to be written to the byte array.
 *  @param buffer - The byte array in which the integer will be written.
 *  @param pos - The position in the byte array where an integer will be
 *               written.
 *  @return void
 */
void intToByteArray(int value, char *buffer, int pos){

    int i = 0;
    int shift = 0;

    for(i = 0; i < 4; i++){

        //shift = (4 - 1 - i) * 8;      // Why?
        shift = (3 - i) * 8;
        buffer[i + pos] = (char)((((unsigned int) value) >> shift) & 0xFF);

    }

    return;

}

/** @brief Reads an integer from a byte array at a specific location.
 *
 *  More detailed explanation...
 *
 *  @param buffer - The byte array from which the integer will be read.
 *  @param pos - The position in the byte array from where an integer will be
 *               read.
 *  @return value - The integer read from the byte array.
 */
int byteArrayToInt(char *buffer, int pos){

    int i = 0;
    int value = 0;
    int shift = 0;

    for(i = 0; i < 4; i++){

        //shift = (4 - 1 - i ) * 8;     // Again, why?
        shift = (3 - i) * 8;
        value += (buffer[i + pos] & 0x000000FF) << shift;

    }

    return value;

}

