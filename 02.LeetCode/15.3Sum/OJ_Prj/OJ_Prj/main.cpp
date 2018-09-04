#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestResult.h>
#include <cppunit/TextOutputter.h>
#include <cppunit/XmlOutputter.h>
#include <cppunit/BriefTestProgressListener.h>

int main()
{
    // Create the event manager and test controller
    CPPUNIT_NS::TestResult controller;

    // Add a listener that colllects test result
    CPPUNIT_NS::TestResultCollector result;
    controller.addListener( &result );

    // Add a listener that print dots as test run.
    CPPUNIT_NS::BriefTestProgressListener progress;
    controller.addListener( &progress );

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry("OJTest");
    runner.addTest(registry.makeTest());

    runner.run(controller);

    // Print test in a text format.
    CPPUNIT_NS::TextOutputter outputter( &result, CPPUNIT_NS::stdCOut() );
    outputter.write();

    // This for XML output
    std::ofstream file( "TestResult.xml" );
    CPPUNIT_NS::XmlOutputter xml( &result, file );
    xml.setStyleSheet( "report.xsl" );
    xml.write();
    file.close();

    char ccc;
    scanf( &ccc );
    return result.wasSuccessful() ? 0 : 1;
}
