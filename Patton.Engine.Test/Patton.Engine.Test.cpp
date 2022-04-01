#include "pch.h"
#include "CppUnitTest.h"
#include <Engine/GameObject.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PattonEngineTest
{
	TEST_CLASS(PattonEngineTest)
	{
	public:
		
        TEST_METHOD(TestMethod1)
        {
            GameObject* gameObject = new GameObject();
            GameComponent* component = new GameComponent();
            gameObject->addComponent(*component);

            GameComponent* retrievedComponent = gameObject->getComponent<GameComponent>();
            Assert::IsNotNull(retrievedComponent);
        }
	};
}
