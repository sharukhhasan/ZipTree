/**
 *
 * Created by Sharukh Hasan on 8/09/16.
 * Copyright © 2016 HyperCryptic Solutions, LLC. All rights reserved.
 *
 */

#ifndef INCLUDE_WTREE_H_
#define INCLUDE_WTREE_H_



#include <stdint.h>
#include <stddef.h>

#include "cdsl_slist.h"

#define DECLARE_WTREE_TRAVERSE_CALLBACK(fn)             BOOL  fn(wtreeNode_t* node,void* arg)

#define DECLARE_ONALLOCATE(fn)                              void* fn(size_t total_sz, size_t* rsz, void* ext_ctx)
#define DECLARE_ONFREE(fn)                                  int fn(void* addr, size_t sz, wtreeNode_t* wtnode, void* ext_ctx)
#define DECLARE_ONREMOVED(fn)                                       void fn(wtreeNode_t* node, void* ext_ctx)
#define DECLARE_ONADDED(fn)                                         void fn(wtreeNode_t* node, void* ext_ctx)
