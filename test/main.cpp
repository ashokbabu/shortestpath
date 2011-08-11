
#include <cppunit/XmlOutputter.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include <fstream>

int main(int argc, char* argv[])
{
  // Get the top level suite from the registry
  CppUnit::Test *suite = CppUnit::TestFactoryRegistry::getRegistry().makeTest();

  // Adds the test to the list of test to run
  CppUnit::TextUi::TestRunner runner;
  runner.addTest( suite );

  std::fstream outfile;
  outfile.open("testresult.xml",std::fstream::out);

  // Change the default outputter to a compiler error format outputter
  runner.setOutputter( new CppUnit::XmlOutputter( &runner.result(), outfile));

  //runner.setOutputter(new CppUnit::CompilerOutputter( &runner.result(),
  //                                                    std::cerr ));

  // Run the tests.
  bool wasSucessful = runner.run();

  // Return error code 1 if the one of test failed.
  return wasSucessful ? 0 : 1;
}
