/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*           (c) 2010 Battelle Energy Alliance, LLC             */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*          Prepared by Battelle Energy Alliance, LLC           */
/*            Under Contract No. DE-AC07-05ID14517              */
/*            With the U. S. Department of Energy               */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/
#include "DarcyThermoMechApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"

template<>
InputParameters validParams<DarcyThermoMechApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;

  return params;
}

DarcyThermoMechApp::DarcyThermoMechApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  DarcyThermoMechApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  DarcyThermoMechApp::associateSyntax(_syntax, _action_factory);
}

DarcyThermoMechApp::~DarcyThermoMechApp()
{
}

void
DarcyThermoMechApp::registerApps()
{
  registerApp(DarcyThermoMechApp);
}

void
DarcyThermoMechApp::registerObjects(Factory & factory)
{
}

void
DarcyThermoMechApp::associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
}
