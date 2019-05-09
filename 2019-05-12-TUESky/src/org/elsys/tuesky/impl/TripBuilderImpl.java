package org.elsys.tuesky.impl;

import org.elsys.tuesky.api.trips.Trip;
import org.elsys.tuesky.api.trips.TripBuilder;
import org.elsys.tuesky.api.trips.TripUnit;

import java.util.ArrayList;
import java.util.List;

public class TripBuilderImpl implements TripBuilder {

    List<TripUnit> units;

    TripBuilderImpl() {
        this.units = new ArrayList<>();
    }

    @Override
    public TripBuilder then(TripUnit nextUnit) {
        // TODO check validness
        units.add(nextUnit);
        return this;
    }

    @Override
    public Trip end() {
        return new TripImpl(units);
    }
}
