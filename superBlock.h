/** @file superBlock.h
 *  @brief Models a superblock in a file system.
 *  
 *  This file contains the superblock structure needed to implement the
 *  UNIX-type file system. Re-written from Dr. Reichherzers's code.
 *
 *  @author Aurburn Jones
 *  @author Derrick Masters
 *  @date 12/03/2019
 *  @info Course COP 4634
 *  @bug No known bugs.
 */

#ifndef SUPERBLOCK_H
#define SUPERBLOCK_H

    typedef struct superBlock{

        int numberOfDiskBlocks;
        int numberOfInodes;
        int firstBlockOfFreeList;

    }superBlock_t;
    
    // FIXME

#endif /* SUPERBLOCK_H */
