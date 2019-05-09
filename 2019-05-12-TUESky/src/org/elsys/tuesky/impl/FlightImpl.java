package org.elsys.tuesky.impl;

import org.elsys.tuesky.api.trips.Flight;

import java.time.Duration;

public class FlightImpl implements Flight {
    private Duration duration;
    private String origin, destination;

    FlightImpl(Duration duration, String origin, String destination) {
        assert(duration != null);
        assert(origin != null);
        assert(destination != null);

        this.duration = duration;
        this.origin = origin;
        this.destination = destination;
    }

    @Override
    public String getOrigin() {
        return origin;
    }

    @Override
    public String getDestination() {
        return destination;
    }

    @Override
    public Duration getDuration() {
        return duration;
    }
}
