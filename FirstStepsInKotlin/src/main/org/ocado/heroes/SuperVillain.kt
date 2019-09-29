package org.ocado.heroes

class SuperVillain(name: String) : Character(name) {
    override val isGood: Boolean = true
    override val universe: Universe? = null

    override fun act() {
        universe?.actNasty(this) ?: throw UniverseError(null)
        println("$name does nasty things! (evil laugh)")
    }
}