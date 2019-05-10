package org.elsys.tuesky.impl;

import org.elsys.tuesky.api.TUESkyException;
import org.elsys.tuesky.api.planner.TripQuery;
import org.elsys.tuesky.api.trips.Flight;
import org.elsys.tuesky.api.trips.Layover;
import org.elsys.tuesky.api.trips.Trip;
import org.elsys.tuesky.api.trips.TripUnit;

import java.time.Duration;
import java.util.List;
import java.util.Objects;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class TripImpl implements Trip {
    private final List<TripUnit> nodes;
    private final int unitsCount;

    TripImpl(List<TripUnit> nodes) {
        this.nodes = nodes;
        unitsCount = nodes.size();
        checkValidness();
    }

    @Override
    public String getOrigin() {
        final TripUnit unit = nodes.get(0);

        assert(unit instanceof Flight);

        return ((Flight) unit).getOrigin();
    }

    @Override
    public String getDestination() {
        final TripUnit unit = nodes.get(unitsCount - 1);

        assert(unit instanceof Flight);

        return ((Flight) unit).getDestination();    }

    @Override
    public Duration getDuration() {
        return nodes.stream()
                .map(TripUnit::getDuration)
                .reduce(Duration.ZERO, Duration::plus);
    }

    @Override
    public Duration getLayoverDuration() {
        return layovers()
                .map(TripUnit::getDuration)
                .reduce(Duration.ZERO, Duration::plus);
    }

    @Override
    public int getFlightsCount() {
        return (int) flights()
                .count();
    }

    @Override
    public boolean matches(TripQuery query) {
        return query.matches(this);
    }

    public List<String> getMiddlePoints() {
        return flights()
                .map(tripUnit -> ((Flight)tripUnit).getOrigin())
                .skip(1)
                .collect(Collectors.toList());

    }

    private Stream<TripUnit> layovers() {
        return nodes.stream()
                .filter(tripUnit -> tripUnit instanceof Layover);
    }

    private Stream<TripUnit> flights() {
        return nodes.stream()
                .filter(tripUnit -> tripUnit instanceof Flight);
    }

    private void checkValidness() {
        List<Flight> flights = flights()
                .map(tripUnit -> (Flight)tripUnit)
                .collect(Collectors.toList());

        for (int i = 0; i < flights.size() - 1; ++i) {
            if (!flights.get(i).getDestination().equals(flights.get(i+1).getOrigin()))
                throw new TUESkyException();
        }
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        TripImpl trip = (TripImpl) o;
        return nodes.equals(trip.nodes);
    }

    @Override
    public int hashCode() {
        return Objects.hash(nodes, unitsCount);
    }
}
