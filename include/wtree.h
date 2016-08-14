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

typedef void* uaddr_t;
typedef struct wtree_node wtreeNode_t;


typedef int (*wt_unmap_func_t) (void* addr, size_t total_sz, wtreeNode_t* wtnode, void* ext_ctx);
typedef void* (*wt_map_func_t) (size_t total_sz, size_t* rsz, void* ext_ctx);
typedef void (*wt_on_merge_t)(wtreeNode_t* merger, wtreeNode_t* mergee, void* ext_ctx);
typedef BOOL (*wt_callback_t) (wtreeNode_t* node,void* arg);

typedef struct {
    void* (*onallocate) (size_t total_sz, size_t* rsz, void* ext_ctx);
    int (*onfree)(void* addr, size_t size,wtreeNode_t* node, void* ext_ctx);
    void (*onremoved)(wtreeNode_t* node, void* ext_ctx);
    void (*onadded)(wtreeNode_t* node, void* ext_ctx);
} wt_adapter;

struct wtree_node {
    wtreeNode_t *left, *right;
    uaddr_t       top;
    uint32_t      size;
    uint32_t      base_size;
};

typedef struct  {
    wtreeNode_t*      entry;
    size_t            total_sz;
    size_t            used_sz;
    size_t            hdr_sz;
    const wt_adapter *adapter;
    void*             ext_ctx;
}wtreeRoot_t;