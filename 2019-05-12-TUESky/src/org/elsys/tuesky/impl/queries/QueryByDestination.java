package org.elsys.tuesky.impl.queries;

import org.elsys.tuesky.api.trips.Trip;

public final class QueryByDestination extends TripQueryImpl {
    private final String expectedDestination;

    public QueryByDestination(final String expectedDestination) {
        this.expectedDestination = expectedDestination;
    }

    @Override
    public boolean matches(Trip trip) {
        return trip.getDestination()
                .equals(expectedDestination);
    }
}
