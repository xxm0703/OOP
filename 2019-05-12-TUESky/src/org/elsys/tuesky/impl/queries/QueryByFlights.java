package org.elsys.tuesky.impl.queries;

import org.elsys.tuesky.api.trips.Trip;

public final class QueryByFlights extends TripQueryImpl {
    private final int maxFlights;

    public QueryByFlights(final int maxFlights) {
        this.maxFlights = maxFlights;
    }

    @Override
    public boolean matches(Trip trip) {
        return trip.getFlightsCount() <= maxFlights;
    }
}
