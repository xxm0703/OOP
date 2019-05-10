package org.elsys.tuesky.impl;

import org.elsys.tuesky.api.trips.Trip;
import org.elsys.tuesky.api.trips.TripBuilder;
import org.elsys.tuesky.api.trips.TripUnit;

import java.util.ArrayList;
import java.util.List;

public class TripBuilderImpl implements TripBuilder {

    private List<TripUnit> units;

    TripBuilderImpl() {
        this.units = new ArrayList<>();
    }

    @Override
    public TripBuilder then(final TripUnit nextUnit) {
        units.add(nextUnit);
        return this;
    }

    @Override
    public Trip end() {
        return new TripImpl(units);
    }
}
