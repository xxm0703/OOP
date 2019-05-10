package org.elsys.tuesky.impl.queries;

import org.elsys.tuesky.api.planner.TripQuery;
import org.elsys.tuesky.api.trips.Trip;

public final class NotQuery extends TripQueryImpl {
    private final TripQuery a;

    NotQuery(final TripQuery a) {
        this.a = a;
    }

    @Override
    public boolean matches(Trip trip) {
        return !a.matches(trip);
    }
}
