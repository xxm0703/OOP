package org.elsys.tuesky.impl.planner;

import org.elsys.tuesky.api.planner.Planner;
import org.elsys.tuesky.api.trips.Trip;
import org.elsys.tuesky.impl.Factory;
import org.elsys.tuesky.impl.PlannerImpl;
import org.elsys.tuesky.impl.Trips;
import org.junit.Before;
import org.junit.Test;

import java.lang.reflect.Array;
import java.time.Duration;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

import static junit.framework.TestCase.assertEquals;
import static junit.framework.TestCase.assertSame;

public class PlannerTest {

    private List<Trip> tripList;
    private Planner planner;

    @Before
    public void initPlanner() {
        Trip trip1 = Factory.startTrip()
                .then(Factory.createFlight("Sofia", "Athens", Duration.ofHours(1)))
                .then(Factory.createLayover(Duration.ofMinutes(90)))
                .then(Factory.createFlight("Athens", "Xania", Duration.ofHours(1)))
                .end();

        Trip trip2 = Factory.startTrip()
                .then(Factory.createFlight("Sofia", "Eindhoven", Duration.ofHours(1)))
                .then(Factory.createLayover(Duration.ofMinutes(90)))
                .then(Factory.createFlight("Eindhoven", "London", Duration.ofHours(1)))
                .then(Factory.createLayover(Duration.ofMinutes(210)))
                .then(Factory.createFlight("London", "Havana", Duration.ofHours(10)))
                .end();

        Trip trip3 = Factory.startTrip()
                .then(Factory.createFlight("Berlin", "Eindhoven", Duration.ofHours(1)))
                .then(Factory.createLayover(Duration.ofMinutes(90)))
                .then(Factory.createFlight("Eindhoven", "London", Duration.ofHours(1)))
                .then(Factory.createLayover(Duration.ofMinutes(210)))
                .then(Factory.createFlight("London", "Havana", Duration.ofHours(10)))
                .then(Factory.createLayover(Duration.ofHours(10)))
                .then(Factory.createFlight("Havana", "San Antonio", Duration.ofHours(10)))
                .end();

        tripList= Arrays.asList(trip1, trip2, trip3);

        planner = new PlannerImpl(tripList);

    }

    @Test
    public void testSearch() {
        assertEquals(tripList.subList(0, 2), planner.search(Trips.withMaxFlights(3)));
        assertEquals(tripList.subList(1, 3), planner.search(Trips.via("London")));
        assertEquals(tripList.subList(0, 0), planner.search(Trips.withMaxDuration(Duration.ofHours(1))));
        assertEquals(tripList.subList(0, 2), planner.search(Trips.withOrigin("Sofia")));
        assertEquals(tripList.subList(1, 2), planner.search(Trips.withDestination("Havana")));
        assertEquals(tripList.subList(0, 2), planner.search(Trips.withMaxLayoverDuration(Duration.ofHours(10))));
        assertEquals(tripList.subList(0, 1), planner.search(Trips.withMaxDuration(Duration.ofHours(10))));
    }
    
    @Test
    public void testMatching() {
        assertEquals(true, planner.anyMatch(Trips.withMaxFlights(3)));
        assertEquals(true, planner.anyMatch(Trips.via("London")));
        assertEquals(false, planner.anyMatch(Trips.withMaxDuration(Duration.ofHours(1))));
        assertEquals(true, planner.anyMatch(Trips.withOrigin("Sofia")));
        assertEquals(true, planner.anyMatch(Trips.withDestination("Havana")));
        assertEquals(false, planner.anyMatch(Trips.withDestination("Brazil")));
        assertEquals(true, planner.anyMatch(Trips.withMaxLayoverDuration(Duration.ofHours(10))));
        assertEquals(true, planner.anyMatch(Trips.withMaxDuration(Duration.ofHours(10))));
    }

    @Test
    public void testCount() {
        assertEquals(2, planner.count(Trips.withMaxFlights(3)));
        assertEquals(2, planner.count(Trips.via("London")));
        assertEquals(0, planner.count(Trips.withMaxDuration(Duration.ofHours(1))));
        assertEquals(2, planner.count(Trips.withOrigin("Sofia")));
        assertEquals(1, planner.count(Trips.withDestination("Havana")));
        assertEquals(2, planner.count(Trips.withMaxLayoverDuration(Duration.ofHours(10))));
        assertEquals(1, planner.count(Trips.withMaxDuration(Duration.ofHours(10))));
    }
}
