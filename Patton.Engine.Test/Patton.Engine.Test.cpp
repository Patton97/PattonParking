#include "pch.h"
#include "CppUnitTest.h"
#include <Engine/Dummy.h>
#include <SFML/Graphics/Transformable.hpp>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PattonEngineTest
{
    TEST_CLASS(PattonEngineTest)
    {
    public:
        
        TEST_METHOD(TestMethod1)
        {
            auto dummy = new Dummy();
            dummy->myTestMethod();
            /*
            GameComponent* component = new GameComponent();
            gameObject->addComponent(*component);

            GameComponent* retrievedComponent = gameObject->getComponent<GameComponent>();
            Assert::IsNotNull(retrievedComponent);
            */
        }
    };
}
