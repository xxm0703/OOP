package org.elsys.tuesky.impl.queries;

import org.elsys.tuesky.api.trips.Trip;

public class QueryByOrigin extends TripQueryImpl {
    private final String expectedOrigin;

    public QueryByOrigin(String expectedOrigin) {
        this.expectedOrigin = expectedOrigin;
    }

    @Override
    public boolean matches(Trip trip) {
        return trip.getOrigin()
                .equals(expectedOrigin);
    }
}