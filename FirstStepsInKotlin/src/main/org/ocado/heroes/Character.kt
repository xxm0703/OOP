package org.ocado.heroes

abstract class Character constructor(protected val name: String) : SpecialPowersCharacter {

    fun templateAct() {
        universe ?: throw UniverseError("null")
        println("$name will act.")
        act()
        println("$name will now have some rest.")
    }
//    abstract override fun act()

}