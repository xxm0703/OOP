package org.elsys.tuesky.impl.queries;

import org.elsys.tuesky.api.planner.TripQuery;
import org.elsys.tuesky.api.trips.Trip;

public class NotQuery extends TripQueryImpl {
    private final TripQuery a;

    public NotQuery(TripQuery a) {
        this.a = a;
    }

    @Override
    public boolean matches(Trip trip) {
        return !a.matches(trip);
    }
}
