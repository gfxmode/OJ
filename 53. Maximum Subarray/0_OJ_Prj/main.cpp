#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

int main()
{
	CppUnit::TextUi::TestRunner runner;
	CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry("OJTest");
	runner.addTest(registry.makeTest());
	bool wasSucessful = runner.run();

	return wasSucessful ? 0 : 1;
} 