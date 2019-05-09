package org.elsys.tuesky.impl;

import org.elsys.tuesky.api.planner.Planner;
import org.elsys.tuesky.api.planner.TripQuery;
import org.elsys.tuesky.api.trips.Trip;

import java.util.ArrayList;
import java.util.List;

public class PlannerImpl implements Planner {
    List<Trip> trips;

    public PlannerImpl(List<Trip> trips) {
        this.trips = trips;
    }

    @Override
    public List<Trip> search(TripQuery query) {
        List<Trip> matching = new ArrayList<>();

        for (Trip trip : trips)
            if (trip.matches(query))
                matching.add(trip);

        return matching;
    }

    @Override
    public boolean anyMatch(TripQuery query) {
        // Not the best way but short enough
        return !search(query).isEmpty();
    }

    @Override
    public int count(TripQuery query) {
        return search(query).size();
    }
}
