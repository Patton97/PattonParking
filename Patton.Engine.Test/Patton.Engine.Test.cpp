#include "pch.h"
#include "CppUnitTest.h"

#include <Engine/GameObject.h>
#include <Engine/GameObject.cpp>
#include <Engine/GameComponent.h>
#include "Engine/Gizmos/LineGizmo.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PattonEngineTest
{
    TEST_CLASS(PattonEngineTest)
    {
    public:
        
        TEST_METHOD(TestMethod1)
        {
            // Dummy dummy;
            // auto transform = dummy.myTestMethod();
            // Assert::IsNotNull(&transform);
            const auto gameObject = new LineGizmo(nullptr, nullptr);
            const auto component = new GameComponent();
            gameObject->addComponent(*component);

            const auto retrievedComponent = gameObject->getComponent<GameComponent>();
            Assert::IsNotNull(retrievedComponent);
        }
    };
}
