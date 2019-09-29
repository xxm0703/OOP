
import kotlin.test.assertFalse
import kotlin.test.assertTrue

@Test fun falseTest() {
    assertFalse(Pairs.checkPairs(listOf(1, 1, 2, 2, 3, 2)))
}

@Test
fun trueTest() {
    assertTrue(Pairs.checkPairs(listOf(5, 6, 5, 6)))
}
