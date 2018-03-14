/*******************************************************************************
* Copyright 2017-2018 Intel Corporation
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
//#include <string>
#include "ngraph/runtime/manager.hpp"
#include "ngraph/function.hpp"
#include "ngraph/runtime/external_function.hpp"
#include "ngraph/runtime/backend.hpp"
#include "pyngraph/runtime/manager.hpp"

namespace py = pybind11;

void regclass_pyngraph_runtime_Manager(py::module m) {
    py::class_<ngraph::runtime::Manager, std::shared_ptr<ngraph::runtime::Manager>> manager(m, "Manager");
    manager.def_static("get", &ngraph::runtime::Manager::get);
    manager.def("compile", &ngraph::runtime::Manager::compile);
    manager.def("allocate_backend", &ngraph::runtime::Manager::allocate_backend);
}


