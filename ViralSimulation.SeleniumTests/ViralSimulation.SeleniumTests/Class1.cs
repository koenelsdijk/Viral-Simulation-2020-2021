using System;
using NUnit.Framework;
using NUnit.Framework.Internal;

namespace ViralSimulation.SeleniumTests
{
    public class Class1
    {
        [Test]
        public void PassTheTest()
        {
            Assert.True(true);
        }

        [Test]
        public void FailTheTest()
        {
            Assert.True(false);
        }
    }
}
