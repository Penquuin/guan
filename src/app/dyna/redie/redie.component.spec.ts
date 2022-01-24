import { ComponentFixture, TestBed } from '@angular/core/testing';

import { RedieComponent } from './redie.component';

describe('RedieComponent', () => {
  let component: RedieComponent;
  let fixture: ComponentFixture<RedieComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ RedieComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(RedieComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
