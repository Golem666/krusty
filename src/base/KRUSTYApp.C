#include "KRUSTYApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
KRUSTYApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

KRUSTYApp::KRUSTYApp(const InputParameters & parameters) : MooseApp(parameters)
{
  KRUSTYApp::registerAll(_factory, _action_factory, _syntax);
}

KRUSTYApp::~KRUSTYApp() {}

void
KRUSTYApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAllObjects<KRUSTYApp>(f, af, syntax);
  Registry::registerObjectsTo(f, {"KRUSTYApp"});
  Registry::registerActionsTo(af, {"KRUSTYApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
KRUSTYApp::registerApps()
{
  registerApp(KRUSTYApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
KRUSTYApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  KRUSTYApp::registerAll(f, af, s);
}
extern "C" void
KRUSTYApp__registerApps()
{
  KRUSTYApp::registerApps();
}
