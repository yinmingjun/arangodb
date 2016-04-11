////////////////////////////////////////////////////////////////////////////////
/// DISCLAIMER
///
/// Copyright 2014-2016 ArangoDB GmbH, Cologne, Germany
/// Copyright 2004-2014 triAGENS GmbH, Cologne, Germany
///
/// Licensed under the Apache License, Version 2.0 (the "License");
/// you may not use this file except in compliance with the License.
/// You may obtain a copy of the License at
///
///     http://www.apache.org/licenses/LICENSE-2.0
///
/// Unless required by applicable law or agreed to in writing, software
/// distributed under the License is distributed on an "AS IS" BASIS,
/// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
/// See the License for the specific language governing permissions and
/// limitations under the License.
///
/// Copyright holder is ArangoDB GmbH, Cologne, Germany
///
/// @author Max Neunhoeffer
////////////////////////////////////////////////////////////////////////////////

#ifndef ARANGOD_AQL_ATTRIBUTE_ACCESSOR_H
#define ARANGOD_AQL_ATTRIBUTE_ACCESSOR_H 1

#include "Basics/Common.h"
#include "Aql/AqlValue.h"
#include "Aql/types.h"

namespace arangodb {
namespace aql {

class AqlItemBlock;
class AqlTransaction;
struct Variable;

/// @brief AttributeAccessor
class AttributeAccessor {
 public:
  AttributeAccessor(std::vector<std::string> const&, Variable const*);
  ~AttributeAccessor() = default;

  /// @brief execute the accessor
  AqlValue get(arangodb::AqlTransaction* trx, AqlItemBlock const*, size_t,
               std::vector<Variable const*> const&,
               std::vector<RegisterId> const&, bool& mustDestroy);

 private:

  /// @brief the attribute names vector (e.g. [ "a", "b", "c" ] for a.b.c)
  std::vector<std::string> const _attributeParts;

  /// @brief full attribute name (e.g. "a.b.c")
  std::string _combinedName;

  /// @brief the accessed variable
  Variable const* _variable;

};

}  // namespace arangodb::aql
}  // namespace arangodb

#endif
