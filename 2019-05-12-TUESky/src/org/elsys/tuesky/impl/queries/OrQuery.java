package org.elsys.tuesky.impl.queries;

import org.elsys.tuesky.api.planner.TripQuery;
import org.elsys.tuesky.api.trips.Trip;

public class OrQuery extends TripQueryImpl {
    private final TripQuery a, b;

    OrQuery(TripQuery a, TripQuery b) {
        this.a = a;
        this.b = b;
    }

    @Override
    public boolean matches(Trip trip) {
        return a.matches(trip) || b.matches(trip);
    }
}
