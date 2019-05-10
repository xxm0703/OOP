package org.elsys.tuesky.impl.queries;

import org.elsys.tuesky.api.planner.TripQuery;
import org.elsys.tuesky.api.trips.Trip;

public abstract class TripQueryImpl implements TripQuery {

    public abstract boolean matches(Trip trip);

    @Override
    public TripQuery and(TripQuery query) {
        return new AndQuery(this, query);
    }

    @Override
    public TripQuery or(TripQuery query) {
        return new OrQuery(this, query);
    }

    @Override
    public TripQuery not() {
        return new NotQuery(this);
    }
}
