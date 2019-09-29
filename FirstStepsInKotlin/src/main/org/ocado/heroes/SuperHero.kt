package org.ocado.heroes

class SuperHero(private val villain: SuperVillain) : Character("") {
    override val universe: Universe? = null
    override val isGood: Boolean = true

    override fun act() {
        universe?.beat(this, villain)
    }
}