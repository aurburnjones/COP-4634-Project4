/** @file inode.h
 *  @brief Models an inode in a file system.
 *  
 *  This file contains the data structure which serves as the inodes for the
 *  UNIX-type filesystem and the function protoype for the initialization of
 *  inodes. Re-written from Dr. Reichherzer's source code.
 *
 *  @author Aurburn Jones
 *  @author Derrick Masters
 *  @date 12/03/2019
 *  @info Course COP 4634
 *  @bug No known bugs.
 */

#ifndef INODE_H
#define INODE_H

    /* ---------- Definitions ---------- */
    
    // Global definition for the maximum number of data block pointers
    #define MAX_POINTERS 250

    /* ---------- Structures ---------- */
    
    // Inode data structure
    typedef struct inode{

        // Indicates if the inode points to a file or a directory
        // A value of 0 indicates that the inode is unused
        int flag;

        // Indicates the owner of the file (an ID)
        int owner;

        // Indicates the size of the file
        int filesize;

        // Specifies the filename in format 'xxxxxxxx.xxx' + NULL
        char filename[12];

        // A list of direct pointers to data blocks of the file
        int pointer[MAX_POINTERS];

    }inode_t;

    /* ---------- Prototypes ---------- */

    /** @brief Initializes all inode_t element values.
     *
     *  More detailed explanation...
     *
     *  @param inode - Pointer to the inode which must be initialized.
     *  @return void
     */
    void initializeInode(inode_t *inode);

#endif /* INODE_H */

