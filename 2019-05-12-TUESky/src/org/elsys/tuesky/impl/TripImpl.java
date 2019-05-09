package org.elsys.tuesky.impl;

import org.elsys.tuesky.api.planner.TripQuery;
import org.elsys.tuesky.api.trips.Flight;
import org.elsys.tuesky.api.trips.Trip;
import org.elsys.tuesky.api.trips.TripUnit;

import java.time.Duration;
import java.util.List;

public class TripImpl implements Trip {
    private List<TripUnit> nodes;
    private int units;

    public TripImpl(List<TripUnit> nodes) {
        this.nodes = nodes;
        units = nodes.size();
    }

    @Override
    public int hashCode() {
        return 0;
    }

    @Override
    public String getOrigin() {
        return ((Flight) nodes.get(units - 1)).getDestination();
    }

    @Override
    public String getDestination() {
        return ((Flight) nodes[0]).getDestination();
    }

    @Override
    public Duration getDuration() {
        return null;
    }

    @Override
    public Duration getLayoverDuration() {
        return null;
    }

    @Override
    public int getFlightsCount() {
        return 0;
    }

    @Override
    public boolean matches(TripQuery query) {
        return false;
    }
}
