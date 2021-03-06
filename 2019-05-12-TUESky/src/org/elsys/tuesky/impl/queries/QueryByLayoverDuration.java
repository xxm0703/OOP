package org.elsys.tuesky.impl.queries;

import org.elsys.tuesky.api.trips.Trip;

import java.time.Duration;

public final class QueryByLayoverDuration extends TripQueryImpl {
    private final Duration maxDuration;

    public QueryByLayoverDuration(final Duration maxDuration) {
        this.maxDuration = maxDuration;
    }

    @Override
    public boolean matches(Trip trip) {
        return trip.getLayoverDuration()
                .compareTo(maxDuration) <= 0;
    }
}
