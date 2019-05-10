package org.elsys.tuesky.impl;

import org.elsys.tuesky.api.planner.Planner;
import org.elsys.tuesky.api.trips.Flight;
import org.elsys.tuesky.api.trips.Layover;
import org.elsys.tuesky.api.trips.Trip;
import org.elsys.tuesky.api.trips.TripBuilder;

import java.time.Duration;
import java.util.List;

public final class Factory {

    public static TripBuilder startTrip() {
        return new TripBuilderImpl();
    }

    public static Flight createFlight(final String from, final String to,final Duration duration) {
        return new FlightImpl(duration, from, to);
    }

    public static Layover createLayover(final Duration duration) {
        return new LayoverImpl(duration);
    }

    public static Planner createPlanner(final List<Trip> trips) {
        return new PlannerImpl(trips);
    }
}
