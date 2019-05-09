package org.elsys.tuesky.impl;

import org.elsys.tuesky.api.planner.TripQuery;
import org.elsys.tuesky.api.trips.Trip;

public class TripQueryImpl implements TripQuery {
    Trip template;

    @Override
    public boolean matches(Trip trip) {
        return false;
    }

    @Override
    public TripQuery and(TripQuery query) {
        return null;
    }

    @Override
    public TripQuery or(TripQuery query) {
        return null;
    }

    @Override
    public TripQuery not() {
        return null;
    }
}
