package org.elsys.tuesky.impl;

import org.elsys.tuesky.api.planner.Planner;
import org.elsys.tuesky.api.planner.TripQuery;
import org.elsys.tuesky.api.trips.Trip;

import java.util.List;
import java.util.stream.Collectors;

public class PlannerImpl implements Planner {
    private final List<Trip> trips;

    PlannerImpl(List<Trip> trips) {
        this.trips = trips;
    }

    @Override
    public List<Trip> search(TripQuery query) {
        return trips.stream()
                .filter((trip) -> trip.matches(query))
                .collect(Collectors.toList());
    }

    @Override
    public boolean anyMatch(TripQuery query) {
        return trips.stream()
                .anyMatch((trip) -> trip.matches(query));
    }

    @Override
    public int count(TripQuery query) {
        return search(query).size();
    }
}
