package org.elsys.tuesky.impl.queries;

import org.elsys.tuesky.api.trips.Trip;

public class QueryByFlights extends TripQueryImpl {
    private final int maxFlights;

    public QueryByFlights(int maxFlights) {
        this.maxFlights = maxFlights;
    }

    @Override
    public boolean matches(Trip trip) {
        return trip.getFlightsCount() <= maxFlights;
    }
}
