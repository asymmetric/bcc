/*
 * Copyright (c) 2015 PLUMgrid, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "cc/bpf_module.h"
#include "cc/bpf_common.h"

extern "C" {
void * bpf_module_create(const char *filename, const char *proto_filename, unsigned flags) {
  auto mod = new ebpf::BPFModule(flags);
  if (mod->load(filename, proto_filename) != 0) {
    delete mod;
    return nullptr;
  }
  return mod;
}

void * bpf_module_create_from_string(const char *text, unsigned flags) {
  auto mod = new ebpf::BPFModule(flags);
  if (mod->load_string(text) != 0) {
    delete mod;
    return nullptr;
  }
  return mod;
}

void bpf_module_destroy(void *program) {
  auto mod = static_cast<ebpf::BPFModule *>(program);
  if (!mod) return;
  delete mod;
}

size_t bpf_num_functions(void *program) {
  auto mod = static_cast<ebpf::BPFModule *>(program);
  if (!mod) return 0;
  return mod->num_functions();
}

const char * bpf_function_name(void *program, size_t id) {
  auto mod = static_cast<ebpf::BPFModule *>(program);
  if (!mod) return nullptr;
  return mod->function_name(id);
}

void * bpf_function_start(void *program, const char *name) {
  auto mod = static_cast<ebpf::BPFModule *>(program);
  if (!mod) return nullptr;
  return mod->function_start(name);
}

void * bpf_function_start_id(void *program, size_t id) {
  auto mod = static_cast<ebpf::BPFModule *>(program);
  if (!mod) return nullptr;
  return mod->function_start(id);
}

size_t bpf_function_size(void *program, const char *name) {
  auto mod = static_cast<ebpf::BPFModule *>(program);
  if (!mod) return 0;
  return mod->function_size(name);
}

size_t bpf_function_size_id(void *program, size_t id) {
  auto mod = static_cast<ebpf::BPFModule *>(program);
  if (!mod) return 0;
  return mod->function_size(id);
}

char * bpf_module_license(void *program) {
  auto mod = static_cast<ebpf::BPFModule *>(program);
  if (!mod) return nullptr;
  return mod->license();
}

unsigned bpf_module_kern_version(void *program) {
  auto mod = static_cast<ebpf::BPFModule *>(program);
  if (!mod) return 0;
  return mod->kern_version();
}

size_t bpf_num_tables(void *program) {
  auto mod = static_cast<ebpf::BPFModule *>(program);
  if (!mod) return -1;
  return mod->num_tables();
}

int bpf_table_fd(void *program, const char *table_name) {
  auto mod = static_cast<ebpf::BPFModule *>(program);
  if (!mod) return -1;
  return mod->table_fd(table_name);
}

int bpf_table_fd_id(void *program, size_t id) {
  auto mod = static_cast<ebpf::BPFModule *>(program);
  if (!mod) return -1;
  return mod->table_fd(id);
}

const char * bpf_table_name(void *program, size_t id) {
  auto mod = static_cast<ebpf::BPFModule *>(program);
  if (!mod) return nullptr;
  return mod->table_name(id);
}

const char * bpf_table_key_desc(void *program, const char *table_name) {
  auto mod = static_cast<ebpf::BPFModule *>(program);
  if (!mod) return nullptr;
  return mod->table_key_desc(table_name);
}

const char * bpf_table_key_desc_id(void *program, size_t id) {
  auto mod = static_cast<ebpf::BPFModule *>(program);
  if (!mod) return nullptr;
  return mod->table_key_desc(id);
}

const char * bpf_table_leaf_desc(void *program, const char *table_name) {
  auto mod = static_cast<ebpf::BPFModule *>(program);
  if (!mod) return nullptr;
  return mod->table_leaf_desc(table_name);
}

const char * bpf_table_leaf_desc_id(void *program, size_t id) {
  auto mod = static_cast<ebpf::BPFModule *>(program);
  if (!mod) return nullptr;
  return mod->table_leaf_desc(id);
}

}