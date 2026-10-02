//* This file is part of the MOOSE framework
//* https://mooseframework.inl.gov
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "KRUSTYTestApp.h"
#include "KRUSTYApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
KRUSTYTestApp::validParams()
{
  InputParameters params = KRUSTYApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

KRUSTYTestApp::KRUSTYTestApp(const InputParameters & parameters) : MooseApp(parameters)
{
  KRUSTYTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

KRUSTYTestApp::~KRUSTYTestApp() {}

void
KRUSTYTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  KRUSTYApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"KRUSTYTestApp"});
    Registry::registerActionsTo(af, {"KRUSTYTestApp"});
  }
}

void
KRUSTYTestApp::registerApps()
{
  registerApp(KRUSTYApp);
  registerApp(KRUSTYTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
KRUSTYTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  KRUSTYTestApp::registerAll(f, af, s);
}
extern "C" void
KRUSTYTestApp__registerApps()
{
  KRUSTYTestApp::registerApps();
}
