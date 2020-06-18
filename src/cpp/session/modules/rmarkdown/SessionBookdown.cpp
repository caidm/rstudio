/*
 * SessionBookdown.cpp
 *
 * Copyright (C) 2020 by RStudio, PBC
 *
 * Unless you have received this program directly from RStudio pursuant
 * to the terms of a commercial license agreement with RStudio, then
 * this program is licensed to you under the terms of version 3 of the
 * GNU Affero General Public License. This program is distributed WITHOUT
 * ANY EXPRESS OR IMPLIED WARRANTY, INCLUDING THOSE OF NON-INFRINGEMENT,
 * MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE. Please refer to the
 * AGPL (http://www.gnu.org/licenses/agpl-3.0.txt) for more details.
 *
 */

#include "SessionBookdown.hpp"

#include <core/Exec.hpp>

#include <session/SessionModuleContext.hpp>

#include "SessionBookdownXRefs.hpp"

namespace rstudio {
namespace session {
namespace modules {
namespace rmarkdown {
namespace bookdown {

using namespace rstudio::core;

namespace {


} // anonymous namespace

bool hasRenumberFootnotes()
{
   return module_context::isPackageVersionInstalled("bookdown", "0.19.3");
}

Error initialize()
{
   ExecBlock initBlock ;
   initBlock.addFunctions()
      (bookdown::xrefs::initialize)
   ;
   return initBlock.execute();
}

} // namespace bookdown
} // namespace rmarkdown
} // namespace modules
} // namespace session
} // namespace rstudio
