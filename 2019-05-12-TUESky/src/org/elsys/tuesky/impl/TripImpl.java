package org.elsys.tuesky.impl;

import org.elsys.tuesky.api.planner.TripQuery;
import org.elsys.tuesky.api.trips.Flight;
import org.elsys.tuesky.api.trips.Layover;
import org.elsys.tuesky.api.trips.Trip;
import org.elsys.tuesky.api.trips.TripUnit;

import java.time.Duration;
import java.util.List;
import java.util.stream.Collector;
import java.util.stream.Stream;

public class TripImpl implements Trip {
    private final List<TripUnit> nodes;
    private final int unitsCount;

    TripImpl(List<TripUnit> nodes) {
        this.nodes = nodes;
        unitsCount = nodes.size();
    }

    @Override
    public String getOrigin() {
        final TripUnit unit = nodes.get(0);
        assert(unit instanceof Flight);
        return ((Flight) unit).getOrigin();
    }

    @Override
    public String getDestination() {
        final TripUnit unit = nodes.get(unitsCount);
        assert(unit instanceof Flight);
        return ((Flight) unit).getDestination();    }

    @Override
    public Duration getDuration() {
        return nodes.stream().map(TripUnit::getDuration)
                .reduce(Duration.ZERO, Duration::plus);
    }

    @Override
    public Duration getLayoverDuration() {
        return nodes.stream().filter(tripUnit -> tripUnit instanceof Layover)
                .map(TripUnit::getDuration)
                .reduce(Duration.ZERO, Duration::plus);
    }

    @Override
    public int getFlightsCount() {
        return (int) nodes.stream().filter(tripUnit -> tripUnit instanceof Flight)
                .count();
    }

    @Override
    public boolean matches(TripQuery query) {
        return query.matches(this);
    }
}
