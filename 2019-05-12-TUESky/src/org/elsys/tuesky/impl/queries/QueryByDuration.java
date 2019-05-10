package org.elsys.tuesky.impl.queries;

import org.elsys.tuesky.api.trips.Trip;

import java.time.Duration;

public final class QueryByDuration extends TripQueryImpl {

    private final Duration maxDuration;

    public QueryByDuration(final Duration maxDuration) {
        this.maxDuration = maxDuration;
    }

    @Override
    public boolean matches(Trip trip) {
        return trip.getDuration()
                .compareTo(maxDuration) <= 0;
    }
}
