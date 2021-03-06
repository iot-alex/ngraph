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

#include "ngraph/op/tanh.hpp"
#include "ngraph/op/multiply.hpp"
#include "ngraph/op/subtract.hpp"

using namespace std;
using namespace ngraph;

op::Tanh::Tanh(const shared_ptr<Node>& arg)
    : UnaryElementwiseArithmetic("Tanh", arg)
{
}

shared_ptr<Node> op::Tanh::copy_with_new_args(const NodeVector& new_args) const
{
    if (new_args.size() != 1)
    {
        throw ngraph_error("Incorrect number of new arguments");
    }
    return make_shared<Tanh>(new_args.at(0));
}

void op::Tanh::generate_adjoints(autodiff::Adjoints& adjoints, const NodeVector& deltas)
{
    auto delta = deltas.at(0);

    auto x = get_argument(0);

    adjoints.add_delta(x, delta - (delta * (shared_from_this() * shared_from_this())));
}
