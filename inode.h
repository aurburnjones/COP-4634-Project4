/** @file inode.h
 *  @brief Models an inode in a file system.
 *  
 *  This file contains the function definition for the initialization of inode
 *  data structures of the UNIX-type filesystem. Re-written from Dr.
 *  Reichherzer's source code.
 *
 *  @author Aurburn Jones
 *  @author Derrick Masters
 *  @date 12/03/2019
 *  @info Course COP 4634
 *  @bug No known bugs.
 */

/* ---------- Includes ---------- */

/* Inode functions header */
#include "inode.h"

/* ---------- Functions ---------- */

/** @brief Initializes all inode_t element values.
 *
 *  More detailed explanation...
 *
 *  @param inode - Pointer to the inode which must be initialized.
 *  @return void
 */
void initializeInode(inode_t *inode){

    int i = 0;

    inode->flag = 0;
    inode->owner = 0;
    inode->filesize = 0;
    inode->filename[0] = '\0';

    for(i = 0; i < MAX_POINTERS; i++)
        inode->pointer[i] = -1;

    return;

}

